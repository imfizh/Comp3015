// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.210505.3

#ifndef WINRT_Windows_UI_ViewManagement_Core_2_H
#define WINRT_Windows_UI_ViewManagement_Core_2_H
#include "winrt/impl/Windows.UI.1.h"
#include "winrt/impl/Windows.UI.ViewManagement.Core.1.h"
WINRT_EXPORT namespace winrt::Windows::UI::ViewManagement::Core
{
    struct __declspec(empty_bases) CoreInputView : winrt::Windows::UI::ViewManagement::Core::ICoreInputView,
        impl::require<CoreInputView, winrt::Windows::UI::ViewManagement::Core::ICoreInputView2, winrt::Windows::UI::ViewManagement::Core::ICoreInputView3>
    {
        CoreInputView(std::nullptr_t) noexcept {}
        CoreInputView(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::ViewManagement::Core::ICoreInputView(ptr, take_ownership_from_abi) {}
        CoreInputView(CoreInputView const&) noexcept = default;
        CoreInputView(CoreInputView&&) noexcept = default;
        CoreInputView& operator=(CoreInputView const&) & noexcept = default;
        CoreInputView& operator=(CoreInputView&&) & noexcept = default;
        static auto GetForCurrentView();
        static auto GetForUIContext(winrt::Windows::UI::UIContext const& context);
    };
    struct __declspec(empty_bases) CoreInputViewOcclusion : winrt::Windows::UI::ViewManagement::Core::ICoreInputViewOcclusion
    {
        CoreInputViewOcclusion(std::nullptr_t) noexcept {}
        CoreInputViewOcclusion(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::ViewManagement::Core::ICoreInputViewOcclusion(ptr, take_ownership_from_abi) {}
        CoreInputViewOcclusion(CoreInputViewOcclusion const&) noexcept = default;
        CoreInputViewOcclusion(CoreInputViewOcclusion&&) noexcept = default;
        CoreInputViewOcclusion& operator=(CoreInputViewOcclusion const&) & noexcept = default;
        CoreInputViewOcclusion& operator=(CoreInputViewOcclusion&&) & noexcept = default;
    };
    struct __declspec(empty_bases) CoreInputViewOcclusionsChangedEventArgs : winrt::Windows::UI::ViewManagement::Core::ICoreInputViewOcclusionsChangedEventArgs
    {
        CoreInputViewOcclusionsChangedEventArgs(std::nullptr_t) noexcept {}
        CoreInputViewOcclusionsChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::ViewManagement::Core::ICoreInputViewOcclusionsChangedEventArgs(ptr, take_ownership_from_abi) {}
        CoreInputViewOcclusionsChangedEventArgs(CoreInputViewOcclusionsChangedEventArgs const&) noexcept = default;
        CoreInputViewOcclusionsChangedEventArgs(CoreInputViewOcclusionsChangedEventArgs&&) noexcept = default;
        CoreInputViewOcclusionsChangedEventArgs& operator=(CoreInputViewOcclusionsChangedEventArgs const&) & noexcept = default;
        CoreInputViewOcclusionsChangedEventArgs& operator=(CoreInputViewOcclusionsChangedEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) CoreInputViewTransferringXYFocusEventArgs : winrt::Windows::UI::ViewManagement::Core::ICoreInputViewTransferringXYFocusEventArgs
    {
        CoreInputViewTransferringXYFocusEventArgs(std::nullptr_t) noexcept {}
        CoreInputViewTransferringXYFocusEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::ViewManagement::Core::ICoreInputViewTransferringXYFocusEventArgs(ptr, take_ownership_from_abi) {}
        CoreInputViewTransferringXYFocusEventArgs(CoreInputViewTransferringXYFocusEventArgs const&) noexcept = default;
        CoreInputViewTransferringXYFocusEventArgs(CoreInputViewTransferringXYFocusEventArgs&&) noexcept = default;
        CoreInputViewTransferringXYFocusEventArgs& operator=(CoreInputViewTransferringXYFocusEventArgs const&) & noexcept = default;
        CoreInputViewTransferringXYFocusEventArgs& operator=(CoreInputViewTransferringXYFocusEventArgs&&) & noexcept = default;
    };
}
#endif
