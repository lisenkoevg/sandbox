#include <iostream>
#include <windows.h>
#include <uiautomationclient.h>
#include <string>
#include <strsafe.h>
#include <algorithm>

#include "sudet.hpp"

using std::endl;
using std::wcerr;
using std::wcout;

IUIAutomation *automation;

void traverse(IUIAutomationTreeWalker *walker, IUIAutomationElement *curElem);
wchar_t *bstrToWchar(BSTR str);

void OpenEntityReaderEx() {

  HRESULT hr = CoInitialize(nullptr);
  if (FAILED(hr)) {
    wprintf(L"CoInitialize failed");
    exit(1);
  } else {
    hr = CoCreateInstance(__uuidof(CUIAutomation8), nullptr,
                          CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&automation));
    if (FAILED(hr)) {
      wprintf(L"CoCreateInstance failed");
      exit(1);
    }
  }
}

void CloseEntityReaderEx() {
  automation->Release();
  ;
}

HWND ExtractEntityEx() {
  IUIAutomationElement *rootElem;
  IUIAutomationElement *curElem;
  IUIAutomationTreeWalker *walker;
  BSTR className;
  HRESULT hr = S_OK;

  HWND hf = GetForegroundWindow();
  //   HWND ha = GetActiveWindow();
  //   wcout << "active: " << ha << ", fg: " << hf << endl;

  hr = automation->ElementFromHandle(hf, &rootElem);
  if (FAILED(hr)) {
    wprintf(L"ElementFromHandle failed, HR: 0x%08x\n", hr);
    exit(1);
  }
  //   wcout << "rootElem: " << rootElem << endl;

  hr = automation->get_ContentViewWalker(&walker);
  if (FAILED(hr)) {
    wprintf(L"get_ContentViewWalker failed, HR: 0x%08x\n", hr);
    exit(1);
  }
  //   wcout << "walker: " << walker << endl;

  traverse(walker, rootElem);
  return hf;
  //   exit(0);
  //   return hf;

  do {
    hr = walker->GetFirstChildElement(rootElem, &curElem);
    if (FAILED(hr)) {
      wprintf(L"GetFirstChildElement failed, HR: 0x%08x\n", hr);
      exit(1);
    }
    wprintf(L"cur element: %p ", curElem);
    //     wcout << "cur element: " << curElem << " ";
    if (curElem) {
      hr = curElem->get_CurrentClassName(&className);
      if (FAILED(hr)) {
        wprintf(L"get_CurrentClassName failed, HR: 0x%08x\n", hr);
        exit(1);
      }
      wprintf(className);
      SysFreeString(className);
      rootElem = curElem;
    }
    wprintf(L"\n");
  } while (curElem);

  wprintf(L"\n");

  return hf;
}

void traverse(IUIAutomationTreeWalker *walker, IUIAutomationElement *curElem) {
  static int pad = 0;

  const int indent = 3;
  wchar_t fmt[30];
  swprintf(fmt, 30, L"%% %dls%%0x%%08x", pad);

  BSTR name;
  HRESULT hr = S_OK;
  IUIAutomationElement *next;
  if (!curElem)
    return;

  wprintf(fmt, "", curElem);

  // controlType
  CONTROLTYPEID controlType;
  hr = curElem->get_CurrentControlType(&controlType);
  if (FAILED(hr)) {
    wprintf(L"get_CurrentControlType failed, HR: 0x%08x\n", hr);
    exit(1);
  }
  wprintf(L" ct:%d", controlType);

  // className
  BSTR className;
  hr = curElem->get_CurrentClassName(&className);
  if (FAILED(hr)) {
    wprintf(L"get_CurrentClassName failed, HR: 0x%08x\n", hr);
    exit(1);
  }
  wprintf(L" cl:%ls", className);
  SysFreeString(className);

  // Name
  hr = curElem->get_CurrentName(&name);
  if (FAILED(hr)) {
    wprintf(L"get_CurrentName failed, HR: 0x%08x\n", hr);
    exit(1);
  }
  std::wstring nameW(name, SysStringLen(name));
  SysFreeString(name);
  //   clang-format off
  std::replace_if(
      nameW.begin(), nameW.end(),
      [](auto ch) { return ch == '\n' || ch == '\r'; }, '_');
  //   clang-format on
  wprintf(L" nm:%ls", nameW.data());

  wprintf(L"\n");

  hr = walker->GetFirstChildElement(curElem, &next);
  if (FAILED(hr)) {
    wprintf(L"GetFirstChildElement failed, HR: 0x%08x\n", hr);
    exit(1);
  }
  if (next) {
    pad += indent;
    traverse(walker, next);
    pad -= indent;
  }
  // Don't traverse root siblings
  if (pad != 0) {
    hr = walker->GetNextSiblingElement(curElem, &next);
    if (FAILED(hr)) {
      wprintf(L"GetNextSiblingElement failed, HR: 0x%08x\n", hr);
      exit(1);
    }
    if (next)
      traverse(walker, next);
  } else {
    wprintf(L"\n");
  }
  std::flush(std::cout);
}
