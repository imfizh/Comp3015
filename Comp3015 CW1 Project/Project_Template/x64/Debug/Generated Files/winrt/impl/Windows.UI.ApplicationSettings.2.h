// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.210505.3

#ifndef WINRT_Windows_UI_ApplicationSettings_2_H
#define WINRT_Windows_UI_ApplicationSettings_2_H
#include "winrt/impl/Windows.Security.Credentials.1.h"
#include "winrt/impl/Windows.System.1.h"
#include "winrt/impl/Windows.UI.Popups.1.h"
#include "winrt/impl/Windows.UI.ApplicationSettings.1.h"
WINRT_EXPORT namespace winrt::Windows::UI::ApplicationSettings
{
    struct CredentialCommandCredentialDeletedHandler : Windows::Foundation::IUnknown
    {
        CredentialCommandCredentialDeletedHandler(std::nullptr_t = nullptr) noexcept {}
        CredentialCommandCredentialDeletedHandler(void* ptr, take_ownership_from_abi_t) noexcept : Windows::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        CredentialCommandCredentialDeletedHandler(CredentialCommandCredentialDeletedHandler const&) noexcept = default;
        CredentialCommandCredentialDeletedHandler(CredentialCommandCredentialDeletedHandler&&) noexcept = default;
        CredentialCommandCredentialDeletedHandler& operator=(CredentialCommandCredentialDeletedHandler const&) & noexcept = default;
        CredentialCommandCredentialDeletedHandler& operator=(CredentialCommandCredentialDeletedHandler&&) & noexcept = default;
        template <typename L> CredentialCommandCredentialDeletedHandler(L lambda);
        template <typename F> CredentialCommandCredentialDeletedHandler(F* function);
        template <typename O, typename M> CredentialCommandCredentialDeletedHandler(O* object, M method);
        template <typename O, typename M> CredentialCommandCredentialDeletedHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> CredentialCommandCredentialDeletedHandler(weak_ref<O>&& object, M method);
        auto operator()(winrt::Windows::UI::ApplicationSettings::CredentialCommand const& command) const;
    };
    struct WebAccountCommandInvokedHandler : Windows::Foundation::IUnknown
    {
        WebAccountCommandInvokedHandler(std::nullptr_t = nullptr) noexcept {}
        WebAccountCommandInvokedHandler(void* ptr, take_ownership_from_abi_t) noexcept : Windows::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        WebAccountCommandInvokedHandler(WebAccountCommandInvokedHandler const&) noexcept = default;
        WebAccountCommandInvokedHandler(WebAccountCommandInvokedHandler&&) noexcept = default;
        WebAccountCommandInvokedHandler& operator=(WebAccountCommandInvokedHandler const&) & noexcept = default;
        WebAccountCommandInvokedHandler& operator=(WebAccountCommandInvokedHandler&&) & noexcept = default;
        template <typename L> WebAccountCommandInvokedHandler(L lambda);
        template <typename F> WebAccountCommandInvokedHandler(F* function);
        template <typename O, typename M> WebAccountCommandInvokedHandler(O* object, M method);
        template <typename O, typename M> WebAccountCommandInvokedHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> WebAccountCommandInvokedHandler(weak_ref<O>&& object, M method);
        auto operator()(winrt::Windows::UI::ApplicationSettings::WebAccountCommand const& command, winrt::Windows::UI::ApplicationSettings::WebAccountInvokedArgs const& args) const;
    };
    struct WebAccountProviderCommandInvokedHandler : Windows::Foundation::IUnknown
    {
        WebAccountProviderCommandInvokedHandler(std::nullptr_t = nullptr) noexcept {}
        WebAccountProviderCommandInvokedHandler(void* ptr, take_ownership_from_abi_t) noexcept : Windows::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        WebAccountProviderCommandInvokedHandler(WebAccountProviderCommandInvokedHandler const&) noexcept = default;
        WebAccountProviderCommandInvokedHandler(WebAccountProviderCommandInvokedHandler&&) noexcept = default;
        WebAccountProviderCommandInvokedHandler& operator=(WebAccountProviderCommandInvokedHandler const&) & noexcept = default;
        WebAccountProviderCommandInvokedHandler& operator=(WebAccountProviderCommandInvokedHandler&&) & noexcept = default;
        template <typename L> WebAccountProviderCommandInvokedHandler(L lambda);
        template <typename F> WebAccountProviderCommandInvokedHandler(F* function);
        template <typename O, typename M> WebAccountProviderCommandInvokedHandler(O* object, M method);
        template <typename O, typename M> WebAccountProviderCommandInvokedHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> WebAccountProviderCommandInvokedHandler(weak_ref<O>&& object, M method);
        auto operator()(winrt::Windows::UI::ApplicationSettings::WebAccountProviderCommand const& command) const;
    };
    struct __declspec(empty_bases) AccountsSettingsPane : winrt::Windows::UI::ApplicationSettings::IAccountsSettingsPane
    {
        AccountsSettingsPane(std::nullptr_t) noexcept {}
        AccountsSettingsPane(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::ApplicationSettings::IAccountsSettingsPane(ptr, take_ownership_from_abi) {}
        AccountsSettingsPane(AccountsSettingsPane const&) noexcept = default;
        AccountsSettingsPane(AccountsSettingsPane&&) noexcept = default;
        AccountsSettingsPane& operator=(AccountsSettingsPane const&) & noexcept = default;
        AccountsSettingsPane& operator=(AccountsSettingsPane&&) & noexcept = default;
        static auto GetForCurrentView();
        static auto Show();
        static auto ShowManageAccountsAsync();
        static auto ShowAddAccountAsync();
        static auto ShowManageAccountsForUserAsync(winrt::Windows::System::User const& user);
        static auto ShowAddAccountForUserAsync(winrt::Windows::System::User const& user);
    };
    struct __declspec(empty_bases) AccountsSettingsPaneCommandsRequestedEventArgs : winrt::Windows::UI::ApplicationSettings::IAccountsSettingsPaneCommandsRequestedEventArgs,
        impl::require<AccountsSettingsPaneCommandsRequestedEventArgs, winrt::Windows::UI::ApplicationSettings::IAccountsSettingsPaneCommandsRequestedEventArgs2>
    {
        AccountsSettingsPaneCommandsRequestedEventArgs(std::nullptr_t) noexcept {}
        AccountsSettingsPaneCommandsRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::ApplicationSettings::IAccountsSettingsPaneCommandsRequestedEventArgs(ptr, take_ownership_from_abi) {}
        AccountsSettingsPaneCommandsRequestedEventArgs(AccountsSettingsPaneCommandsRequestedEventArgs const&) noexcept = default;
        AccountsSettingsPaneCommandsRequestedEventArgs(AccountsSettingsPaneCommandsRequestedEventArgs&&) noexcept = default;
        AccountsSettingsPaneCommandsRequestedEventArgs& operator=(AccountsSettingsPaneCommandsRequestedEventArgs const&) & noexcept = default;
        AccountsSettingsPaneCommandsRequestedEventArgs& operator=(AccountsSettingsPaneCommandsRequestedEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) AccountsSettingsPaneEventDeferral : winrt::Windows::UI::ApplicationSettings::IAccountsSettingsPaneEventDeferral
    {
        AccountsSettingsPaneEventDeferral(std::nullptr_t) noexcept {}
        AccountsSettingsPaneEventDeferral(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::ApplicationSettings::IAccountsSettingsPaneEventDeferral(ptr, take_ownership_from_abi) {}
        AccountsSettingsPaneEventDeferral(AccountsSettingsPaneEventDeferral const&) noexcept = default;
        AccountsSettingsPaneEventDeferral(AccountsSettingsPaneEventDeferral&&) noexcept = default;
        AccountsSettingsPaneEventDeferral& operator=(AccountsSettingsPaneEventDeferral const&) & noexcept = default;
        AccountsSettingsPaneEventDeferral& operator=(AccountsSettingsPaneEventDeferral&&) & noexcept = default;
    };
    struct __declspec(empty_bases) CredentialCommand : winrt::Windows::UI::ApplicationSettings::ICredentialCommand
    {
        CredentialCommand(std::nullptr_t) noexcept {}
        CredentialCommand(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::ApplicationSettings::ICredentialCommand(ptr, take_ownership_from_abi) {}
        explicit CredentialCommand(winrt::Windows::Security::Credentials::PasswordCredential const& passwordCredential);
        CredentialCommand(winrt::Windows::Security::Credentials::PasswordCredential const& passwordCredential, winrt::Windows::UI::ApplicationSettings::CredentialCommandCredentialDeletedHandler const& deleted);
        CredentialCommand(CredentialCommand const&) noexcept = default;
        CredentialCommand(CredentialCommand&&) noexcept = default;
        CredentialCommand& operator=(CredentialCommand const&) & noexcept = default;
        CredentialCommand& operator=(CredentialCommand&&) & noexcept = default;
    };
    struct __declspec(empty_bases) SettingsCommand : winrt::Windows::UI::Popups::IUICommand
    {
        SettingsCommand(std::nullptr_t) noexcept {}
        SettingsCommand(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::Popups::IUICommand(ptr, take_ownership_from_abi) {}
        SettingsCommand(winrt::Windows::Foundation::IInspectable const& settingsCommandId, param::hstring const& label, winrt::Windows::UI::Popups::UICommandInvokedHandler const& handler);
        SettingsCommand(SettingsCommand const&) noexcept = default;
        SettingsCommand(SettingsCommand&&) noexcept = default;
        SettingsCommand& operator=(SettingsCommand const&) & noexcept = default;
        SettingsCommand& operator=(SettingsCommand&&) & noexcept = default;
        [[nodiscard]] static auto AccountsCommand();
    };
    struct __declspec(empty_bases) SettingsPane : winrt::Windows::UI::ApplicationSettings::ISettingsPane
    {
        SettingsPane(std::nullptr_t) noexcept {}
        SettingsPane(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::ApplicationSettings::ISettingsPane(ptr, take_ownership_from_abi) {}
        SettingsPane(SettingsPane const&) noexcept = default;
        SettingsPane(SettingsPane&&) noexcept = default;
        SettingsPane& operator=(SettingsPane const&) & noexcept = default;
        SettingsPane& operator=(SettingsPane&&) & noexcept = default;
        static auto GetForCurrentView();
        static auto Show();
        [[nodiscard]] static auto Edge();
    };
    struct __declspec(empty_bases) SettingsPaneCommandsRequest : winrt::Windows::UI::ApplicationSettings::ISettingsPaneCommandsRequest
    {
        SettingsPaneCommandsRequest(std::nullptr_t) noexcept {}
        SettingsPaneCommandsRequest(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::ApplicationSettings::ISettingsPaneCommandsRequest(ptr, take_ownership_from_abi) {}
        SettingsPaneCommandsRequest(SettingsPaneCommandsRequest const&) noexcept = default;
        SettingsPaneCommandsRequest(SettingsPaneCommandsRequest&&) noexcept = default;
        SettingsPaneCommandsRequest& operator=(SettingsPaneCommandsRequest const&) & noexcept = default;
        SettingsPaneCommandsRequest& operator=(SettingsPaneCommandsRequest&&) & noexcept = default;
    };
    struct __declspec(empty_bases) SettingsPaneCommandsRequestedEventArgs : winrt::Windows::UI::ApplicationSettings::ISettingsPaneCommandsRequestedEventArgs
    {
        SettingsPaneCommandsRequestedEventArgs(std::nullptr_t) noexcept {}
        SettingsPaneCommandsRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::ApplicationSettings::ISettingsPaneCommandsRequestedEventArgs(ptr, take_ownership_from_abi) {}
        SettingsPaneCommandsRequestedEventArgs(SettingsPaneCommandsRequestedEventArgs const&) noexcept = default;
        SettingsPaneCommandsRequestedEventArgs(SettingsPaneCommandsRequestedEventArgs&&) noexcept = default;
        SettingsPaneCommandsRequestedEventArgs& operator=(SettingsPaneCommandsRequestedEventArgs const&) & noexcept = default;
        SettingsPaneCommandsRequestedEventArgs& operator=(SettingsPaneCommandsRequestedEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) WebAccountCommand : winrt::Windows::UI::ApplicationSettings::IWebAccountCommand
    {
        WebAccountCommand(std::nullptr_t) noexcept {}
        WebAccountCommand(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::ApplicationSettings::IWebAccountCommand(ptr, take_ownership_from_abi) {}
        WebAccountCommand(winrt::Windows::Security::Credentials::WebAccount const& webAccount, winrt::Windows::UI::ApplicationSettings::WebAccountCommandInvokedHandler const& invoked, winrt::Windows::UI::ApplicationSettings::SupportedWebAccountActions const& actions);
        WebAccountCommand(WebAccountCommand const&) noexcept = default;
        WebAccountCommand(WebAccountCommand&&) noexcept = default;
        WebAccountCommand& operator=(WebAccountCommand const&) & noexcept = default;
        WebAccountCommand& operator=(WebAccountCommand&&) & noexcept = default;
    };
    struct __declspec(empty_bases) WebAccountInvokedArgs : winrt::Windows::UI::ApplicationSettings::IWebAccountInvokedArgs
    {
        WebAccountInvokedArgs(std::nullptr_t) noexcept {}
        WebAccountInvokedArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::ApplicationSettings::IWebAccountInvokedArgs(ptr, take_ownership_from_abi) {}
        WebAccountInvokedArgs(WebAccountInvokedArgs const&) noexcept = default;
        WebAccountInvokedArgs(WebAccountInvokedArgs&&) noexcept = default;
        WebAccountInvokedArgs& operator=(WebAccountInvokedArgs const&) & noexcept = default;
        WebAccountInvokedArgs& operator=(WebAccountInvokedArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) WebAccountProviderCommand : winrt::Windows::UI::ApplicationSettings::IWebAccountProviderCommand
    {
        WebAccountProviderCommand(std::nullptr_t) noexcept {}
        WebAccountProviderCommand(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::ApplicationSettings::IWebAccountProviderCommand(ptr, take_ownership_from_abi) {}
        WebAccountProviderCommand(winrt::Windows::Security::Credentials::WebAccountProvider const& webAccountProvider, winrt::Windows::UI::ApplicationSettings::WebAccountProviderCommandInvokedHandler const& invoked);
        WebAccountProviderCommand(WebAccountProviderCommand const&) noexcept = default;
        WebAccountProviderCommand(WebAccountProviderCommand&&) noexcept = default;
        WebAccountProviderCommand& operator=(WebAccountProviderCommand const&) & noexcept = default;
        WebAccountProviderCommand& operator=(WebAccountProviderCommand&&) & noexcept = default;
    };
}
#endif
