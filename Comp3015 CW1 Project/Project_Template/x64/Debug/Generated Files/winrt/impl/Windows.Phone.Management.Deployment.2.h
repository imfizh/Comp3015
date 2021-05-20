// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.210505.3

#ifndef WINRT_Windows_Phone_Management_Deployment_2_H
#define WINRT_Windows_Phone_Management_Deployment_2_H
#include "winrt/impl/Windows.Foundation.1.h"
#include "winrt/impl/Windows.Foundation.Collections.1.h"
#include "winrt/impl/Windows.Management.Deployment.1.h"
#include "winrt/impl/Windows.Phone.Management.Deployment.1.h"
WINRT_EXPORT namespace winrt::Windows::Phone::Management::Deployment
{
    struct __declspec(empty_bases) Enterprise : winrt::Windows::Phone::Management::Deployment::IEnterprise
    {
        Enterprise(std::nullptr_t) noexcept {}
        Enterprise(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Phone::Management::Deployment::IEnterprise(ptr, take_ownership_from_abi) {}
        Enterprise(Enterprise const&) noexcept = default;
        Enterprise(Enterprise&&) noexcept = default;
        Enterprise& operator=(Enterprise const&) & noexcept = default;
        Enterprise& operator=(Enterprise&&) & noexcept = default;
    };
    struct EnterpriseEnrollmentManager
    {
        EnterpriseEnrollmentManager() = delete;
        [[nodiscard]] static auto EnrolledEnterprises();
        [[nodiscard]] static auto CurrentEnterprise();
        static auto ValidateEnterprisesAsync();
        static auto RequestEnrollmentAsync(param::hstring const& enrollmentToken);
        static auto RequestUnenrollmentAsync(winrt::Windows::Phone::Management::Deployment::Enterprise const& enterprise);
    };
    struct __declspec(empty_bases) EnterpriseEnrollmentResult : winrt::Windows::Phone::Management::Deployment::IEnterpriseEnrollmentResult
    {
        EnterpriseEnrollmentResult(std::nullptr_t) noexcept {}
        EnterpriseEnrollmentResult(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Phone::Management::Deployment::IEnterpriseEnrollmentResult(ptr, take_ownership_from_abi) {}
        EnterpriseEnrollmentResult(EnterpriseEnrollmentResult const&) noexcept = default;
        EnterpriseEnrollmentResult(EnterpriseEnrollmentResult&&) noexcept = default;
        EnterpriseEnrollmentResult& operator=(EnterpriseEnrollmentResult const&) & noexcept = default;
        EnterpriseEnrollmentResult& operator=(EnterpriseEnrollmentResult&&) & noexcept = default;
    };
    struct InstallationManager
    {
        InstallationManager() = delete;
        static auto AddPackageAsync(param::hstring const& title, winrt::Windows::Foundation::Uri const& sourceLocation);
        static auto AddPackageAsync(param::hstring const& title, winrt::Windows::Foundation::Uri const& sourceLocation, param::hstring const& instanceId, param::hstring const& offerId, winrt::Windows::Foundation::Uri const& license);
        static auto GetPendingPackageInstalls();
        static auto FindPackagesForCurrentPublisher();
        static auto FindPackages();
        static auto RemovePackageAsync(param::hstring const& packageFullName, winrt::Windows::Management::Deployment::RemovalOptions const& removalOptions);
        static auto RegisterPackageAsync(winrt::Windows::Foundation::Uri const& manifestUri, param::async_iterable<winrt::Windows::Foundation::Uri> const& dependencyPackageUris, winrt::Windows::Management::Deployment::DeploymentOptions const& deploymentOptions);
        static auto FindPackages(param::hstring const& packageName, param::hstring const& packagePublisher);
    };
    struct __declspec(empty_bases) PackageInstallResult : winrt::Windows::Phone::Management::Deployment::IPackageInstallResult,
        impl::require<PackageInstallResult, winrt::Windows::Phone::Management::Deployment::IPackageInstallResult2>
    {
        PackageInstallResult(std::nullptr_t) noexcept {}
        PackageInstallResult(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Phone::Management::Deployment::IPackageInstallResult(ptr, take_ownership_from_abi) {}
        PackageInstallResult(PackageInstallResult const&) noexcept = default;
        PackageInstallResult(PackageInstallResult&&) noexcept = default;
        PackageInstallResult& operator=(PackageInstallResult const&) & noexcept = default;
        PackageInstallResult& operator=(PackageInstallResult&&) & noexcept = default;
    };
}
#endif
