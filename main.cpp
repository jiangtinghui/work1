#include <iostream>
#include<Windows.h>

int main() {
//    std::cout << "Hello, World!" << std::endl;
    HMODULE dllHandle = LoadLibrary("E:/MyDll/cmake-build-debug/libMyDll.dll");
    //这里用一个句柄用来标识已经加载的DLL
    if(dllHandle) {
        typedef void (*Message)();
        Message displayMessage = (Message) GetProcAddress(dllHandle, "Message");
        //GetProcAddress函数是windowsAPI中的函数，用于获取指定函数的地址
        //这里是获取地址

        if (displayMessage) {
            displayMessage();// 调用通过 GetProcAddress 获取的函数地址
        } else {
//            DWORD error = GetLastError();
            //GetLastError 函数不接受任何参数，它直接返回调用线程的最近一次发生错误的错误代码。
            std::cout << "Failed to get function address!!" << std::endl;
        }

        FreeLibrary(dllHandle);

    }else {
        //如果句柄为空的话，那么就表明下载失败
        std::cout<<"Failed to load DLL!"<<std::endl;
    }
    return 0;
}
