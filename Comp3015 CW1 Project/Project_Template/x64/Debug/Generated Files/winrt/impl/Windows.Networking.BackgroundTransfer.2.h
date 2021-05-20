// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.210505.3

#ifndef WINRT_Windows_Networking_BackgroundTransfer_2_H
#define WINRT_Windows_Networking_BackgroundTransfer_2_H
#include "winrt/impl/Windows.Foundation.2.h"
#include "winrt/impl/Windows.Foundation.Collections.2.h"
#include "winrt/impl/Windows.Networking.BackgroundTransfer.1.h"
WINRT_EXPORT namespace winrt::Windows::Networking::BackgroundTransfer
{
    struct BackgroundDownloadProgress
    {
        uint64_t BytesReceived;
        uint64_t TotalBytesToReceive;
        winrt::Windows::Networking::BackgroundTransfer::BackgroundTransferStatus Status;
        bool HasResponseChanged;
        bool HasRestarted;
    };
    inline bool operator==(BackgroundDownloadProgress const& left, BackgroundDownloadProgress const& right) noexcept
    {
        return left.BytesReceived == right.BytesReceived && left.TotalBytesToReceive == right.TotalBytesToReceive && left.Status == right.Status && left.HasResponseChanged == right.HasResponseChanged && left.HasRestarted == right.HasRestarted;
    }
    inline bool operator!=(BackgroundDownloadProgress const& left, BackgroundDownloadProgress const& right) noexcept
    {
        return !(left == right);
    }
    struct BackgroundTransferFileRange
    {
        uint64_t Offset;
        uint64_t Length;
    };
    inline bool operator==(BackgroundTransferFileRange const& left, BackgroundTransferFileRange const& right) noexcept
    {
        return left.Offset == right.Offset && left.Length == right.Length;
    }
    inline bool operator!=(BackgroundTransferFileRange const& left, BackgroundTransferFileRange const& right) noexcept
    {
        return !(left == right);
    }
    struct BackgroundUploadProgress
    {
        uint64_t BytesReceived;
        uint64_t BytesSent;
        uint64_t TotalBytesToReceive;
        uint64_t TotalBytesToSend;
        winrt::Windows::Networking::BackgroundTransfer::BackgroundTransferStatus Status;
        bool HasResponseChanged;
        bool HasRestarted;
    };
    inline bool operator==(BackgroundUploadProgress const& left, BackgroundUploadProgress const& right) noexcept
    {
        return left.BytesReceived == right.BytesReceived && left.BytesSent == right.BytesSent && left.TotalBytesToReceive == right.TotalBytesToReceive && left.TotalBytesToSend == right.TotalBytesToSend && left.Status == right.Status && left.HasResponseChanged == right.HasResponseChanged && left.HasRestarted == right.HasRestarted;
    }
    inline bool operator!=(BackgroundUploadProgress const& left, BackgroundUploadProgress const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) BackgroundDownloader : winrt::Windows::Networking::BackgroundTransfer::IBackgroundDownloader,
        impl::require<BackgroundDownloader, winrt::Windows::Networking::BackgroundTransfer::IBackgroundDownloader2, winrt::Windows::Networking::BackgroundTransfer::IBackgroundDownloader3>
    {
        BackgroundDownloader(std::nullptr_t) noexcept {}
        BackgroundDownloader(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Networking::BackgroundTransfer::IBackgroundDownloader(ptr, take_ownership_from_abi) {}
        BackgroundDownloader();
        explicit BackgroundDownloader(winrt::Windows::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup const& completionGroup);
        BackgroundDownloader(BackgroundDownloader const&) noexcept = default;
        BackgroundDownloader(BackgroundDownloader&&) noexcept = default;
        BackgroundDownloader& operator=(BackgroundDownloader const&) & noexcept = default;
        BackgroundDownloader& operator=(BackgroundDownloader&&) & noexcept = default;
        static auto GetCurrentDownloadsAsync();
        static auto GetCurrentDownloadsAsync(param::hstring const& group);
        static auto GetCurrentDownloadsForTransferGroupAsync(winrt::Windows::Networking::BackgroundTransfer::BackgroundTransferGroup const& group);
        static auto RequestUnconstrainedDownloadsAsync(param::async_iterable<winrt::Windows::Networking::BackgroundTransfer::DownloadOperation> const& operations);
    };
    struct __declspec(empty_bases) BackgroundTransferCompletionGroup : winrt::Windows::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroup
    {
        BackgroundTransferCompletionGroup(std::nullptr_t) noexcept {}
        BackgroundTransferCompletionGroup(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroup(ptr, take_ownership_from_abi) {}
        BackgroundTransferCompletionGroup();
        BackgroundTransferCompletionGroup(BackgroundTransferCompletionGroup const&) noexcept = default;
        BackgroundTransferCompletionGroup(BackgroundTransferCompletionGroup&&) noexcept = default;
        BackgroundTransferCompletionGroup& operator=(BackgroundTransferCompletionGroup const&) & noexcept = default;
        BackgroundTransferCompletionGroup& operator=(BackgroundTransferCompletionGroup&&) & noexcept = default;
    };
    struct __declspec(empty_bases) BackgroundTransferCompletionGroupTriggerDetails : winrt::Windows::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroupTriggerDetails
    {
        BackgroundTransferCompletionGroupTriggerDetails(std::nullptr_t) noexcept {}
        BackgroundTransferCompletionGroupTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroupTriggerDetails(ptr, take_ownership_from_abi) {}
        BackgroundTransferCompletionGroupTriggerDetails(BackgroundTransferCompletionGroupTriggerDetails const&) noexcept = default;
        BackgroundTransferCompletionGroupTriggerDetails(BackgroundTransferCompletionGroupTriggerDetails&&) noexcept = default;
        BackgroundTransferCompletionGroupTriggerDetails& operator=(BackgroundTransferCompletionGroupTriggerDetails const&) & noexcept = default;
        BackgroundTransferCompletionGroupTriggerDetails& operator=(BackgroundTransferCompletionGroupTriggerDetails&&) & noexcept = default;
    };
    struct __declspec(empty_bases) BackgroundTransferContentPart : winrt::Windows::Networking::BackgroundTransfer::IBackgroundTransferContentPart
    {
        BackgroundTransferContentPart(std::nullptr_t) noexcept {}
        BackgroundTransferContentPart(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Networking::BackgroundTransfer::IBackgroundTransferContentPart(ptr, take_ownership_from_abi) {}
        BackgroundTransferContentPart();
        explicit BackgroundTransferContentPart(param::hstring const& name);
        BackgroundTransferContentPart(param::hstring const& name, param::hstring const& fileName);
        BackgroundTransferContentPart(BackgroundTransferContentPart const&) noexcept = default;
        BackgroundTransferContentPart(BackgroundTransferContentPart&&) noexcept = default;
        BackgroundTransferContentPart& operator=(BackgroundTransferContentPart const&) & noexcept = default;
        BackgroundTransferContentPart& operator=(BackgroundTransferContentPart&&) & noexcept = default;
    };
    struct BackgroundTransferError
    {
        BackgroundTransferError() = delete;
        static auto GetStatus(int32_t hresult);
    };
    struct __declspec(empty_bases) BackgroundTransferGroup : winrt::Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup
    {
        BackgroundTransferGroup(std::nullptr_t) noexcept {}
        BackgroundTransferGroup(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup(ptr, take_ownership_from_abi) {}
        BackgroundTransferGroup(BackgroundTransferGroup const&) noexcept = default;
        BackgroundTransferGroup(BackgroundTransferGroup&&) noexcept = default;
        BackgroundTransferGroup& operator=(BackgroundTransferGroup const&) & noexcept = default;
        BackgroundTransferGroup& operator=(BackgroundTransferGroup&&) & noexcept = default;
        static auto CreateGroup(param::hstring const& name);
    };
    struct __declspec(empty_bases) BackgroundTransferRangesDownloadedEventArgs : winrt::Windows::Networking::BackgroundTransfer::IBackgroundTransferRangesDownloadedEventArgs
    {
        BackgroundTransferRangesDownloadedEventArgs(std::nullptr_t) noexcept {}
        BackgroundTransferRangesDownloadedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Networking::BackgroundTransfer::IBackgroundTransferRangesDownloadedEventArgs(ptr, take_ownership_from_abi) {}
        BackgroundTransferRangesDownloadedEventArgs(BackgroundTransferRangesDownloadedEventArgs const&) noexcept = default;
        BackgroundTransferRangesDownloadedEventArgs(BackgroundTransferRangesDownloadedEventArgs&&) noexcept = default;
        BackgroundTransferRangesDownloadedEventArgs& operator=(BackgroundTransferRangesDownloadedEventArgs const&) & noexcept = default;
        BackgroundTransferRangesDownloadedEventArgs& operator=(BackgroundTransferRangesDownloadedEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) BackgroundUploader : winrt::Windows::Networking::BackgroundTransfer::IBackgroundUploader,
        impl::require<BackgroundUploader, winrt::Windows::Networking::BackgroundTransfer::IBackgroundUploader2, winrt::Windows::Networking::BackgroundTransfer::IBackgroundUploader3>
    {
        BackgroundUploader(std::nullptr_t) noexcept {}
        BackgroundUploader(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Networking::BackgroundTransfer::IBackgroundUploader(ptr, take_ownership_from_abi) {}
        BackgroundUploader();
        explicit BackgroundUploader(winrt::Windows::Networking::BackgroundTransfer::BackgroundTransferCompletionGroup const& completionGroup);
        BackgroundUploader(BackgroundUploader const&) noexcept = default;
        BackgroundUploader(BackgroundUploader&&) noexcept = default;
        BackgroundUploader& operator=(BackgroundUploader const&) & noexcept = default;
        BackgroundUploader& operator=(BackgroundUploader&&) & noexcept = default;
        static auto GetCurrentUploadsAsync();
        static auto GetCurrentUploadsAsync(param::hstring const& group);
        static auto GetCurrentUploadsForTransferGroupAsync(winrt::Windows::Networking::BackgroundTransfer::BackgroundTransferGroup const& group);
        static auto RequestUnconstrainedUploadsAsync(param::async_iterable<winrt::Windows::Networking::BackgroundTransfer::UploadOperation> const& operations);
    };
    struct ContentPrefetcher
    {
        ContentPrefetcher() = delete;
        [[nodiscard]] static auto ContentUris();
        static auto IndirectContentUri(winrt::Windows::Foundation::Uri const& value);
        [[nodiscard]] static auto IndirectContentUri();
        [[nodiscard]] static auto LastSuccessfulPrefetchTime();
    };
    struct __declspec(empty_bases) DownloadOperation : winrt::Windows::Networking::BackgroundTransfer::IDownloadOperation,
        impl::require<DownloadOperation, winrt::Windows::Networking::BackgroundTransfer::IBackgroundTransferOperationPriority, winrt::Windows::Networking::BackgroundTransfer::IDownloadOperation2, winrt::Windows::Networking::BackgroundTransfer::IDownloadOperation3, winrt::Windows::Networking::BackgroundTransfer::IDownloadOperation4>
    {
        DownloadOperation(std::nullptr_t) noexcept {}
        DownloadOperation(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Networking::BackgroundTransfer::IDownloadOperation(ptr, take_ownership_from_abi) {}
        DownloadOperation(DownloadOperation const&) noexcept = default;
        DownloadOperation(DownloadOperation&&) noexcept = default;
        DownloadOperation& operator=(DownloadOperation const&) & noexcept = default;
        DownloadOperation& operator=(DownloadOperation&&) & noexcept = default;
        using winrt::Windows::Networking::BackgroundTransfer::IDownloadOperation::RequestedUri;
        using impl::consume_t<DownloadOperation, winrt::Windows::Networking::BackgroundTransfer::IDownloadOperation3>::RequestedUri;
    };
    struct __declspec(empty_bases) ResponseInformation : winrt::Windows::Networking::BackgroundTransfer::IResponseInformation
    {
        ResponseInformation(std::nullptr_t) noexcept {}
        ResponseInformation(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Networking::BackgroundTransfer::IResponseInformation(ptr, take_ownership_from_abi) {}
        ResponseInformation(ResponseInformation const&) noexcept = default;
        ResponseInformation(ResponseInformation&&) noexcept = default;
        ResponseInformation& operator=(ResponseInformation const&) & noexcept = default;
        ResponseInformation& operator=(ResponseInformation&&) & noexcept = default;
    };
    struct __declspec(empty_bases) UnconstrainedTransferRequestResult : winrt::Windows::Networking::BackgroundTransfer::IUnconstrainedTransferRequestResult
    {
        UnconstrainedTransferRequestResult(std::nullptr_t) noexcept {}
        UnconstrainedTransferRequestResult(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Networking::BackgroundTransfer::IUnconstrainedTransferRequestResult(ptr, take_ownership_from_abi) {}
        UnconstrainedTransferRequestResult(UnconstrainedTransferRequestResult const&) noexcept = default;
        UnconstrainedTransferRequestResult(UnconstrainedTransferRequestResult&&) noexcept = default;
        UnconstrainedTransferRequestResult& operator=(UnconstrainedTransferRequestResult const&) & noexcept = default;
        UnconstrainedTransferRequestResult& operator=(UnconstrainedTransferRequestResult&&) & noexcept = default;
    };
    struct __declspec(empty_bases) UploadOperation : winrt::Windows::Networking::BackgroundTransfer::IUploadOperation,
        impl::require<UploadOperation, winrt::Windows::Networking::BackgroundTransfer::IBackgroundTransferOperationPriority, winrt::Windows::Networking::BackgroundTransfer::IUploadOperation2, winrt::Windows::Networking::BackgroundTransfer::IUploadOperation3>
    {
        UploadOperation(std::nullptr_t) noexcept {}
        UploadOperation(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Networking::BackgroundTransfer::IUploadOperation(ptr, take_ownership_from_abi) {}
        UploadOperation(UploadOperation const&) noexcept = default;
        UploadOperation(UploadOperation&&) noexcept = default;
        UploadOperation& operator=(UploadOperation const&) & noexcept = default;
        UploadOperation& operator=(UploadOperation&&) & noexcept = default;
    };
}
#endif
