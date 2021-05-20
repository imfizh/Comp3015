// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.210505.3

#ifndef WINRT_Windows_Devices_Display_1_H
#define WINRT_Windows_Devices_Display_1_H
#include "winrt/impl/Windows.Devices.Display.0.h"
WINRT_EXPORT namespace winrt::Windows::Devices::Display
{
    struct __declspec(empty_bases) IDisplayMonitor :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IDisplayMonitor>
    {
        IDisplayMonitor(std::nullptr_t = nullptr) noexcept {}
        IDisplayMonitor(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IDisplayMonitor(IDisplayMonitor const&) noexcept = default;
        IDisplayMonitor(IDisplayMonitor&&) noexcept = default;
        IDisplayMonitor& operator=(IDisplayMonitor const&) & noexcept = default;
        IDisplayMonitor& operator=(IDisplayMonitor&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IDisplayMonitorStatics :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IDisplayMonitorStatics>
    {
        IDisplayMonitorStatics(std::nullptr_t = nullptr) noexcept {}
        IDisplayMonitorStatics(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IDisplayMonitorStatics(IDisplayMonitorStatics const&) noexcept = default;
        IDisplayMonitorStatics(IDisplayMonitorStatics&&) noexcept = default;
        IDisplayMonitorStatics& operator=(IDisplayMonitorStatics const&) & noexcept = default;
        IDisplayMonitorStatics& operator=(IDisplayMonitorStatics&&) & noexcept = default;
    };
}
#endif