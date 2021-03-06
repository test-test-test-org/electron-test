// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE-CHROMIUM file.

#ifndef SHELL_BROWSER_MEDIA_MEDIA_STREAM_DEVICES_CONTROLLER_H_
#define SHELL_BROWSER_MEDIA_MEDIA_STREAM_DEVICES_CONTROLLER_H_

#include "content/public/browser/web_contents_delegate.h"
#include "third_party/blink/public/common/mediastream/media_stream_request.h"

namespace electron {

class MediaStreamDevicesController {
 public:
  MediaStreamDevicesController(const content::MediaStreamRequest& request,
                               content::MediaResponseCallback callback);

  virtual ~MediaStreamDevicesController();

  // disable copy
  MediaStreamDevicesController(const MediaStreamDevicesController&) = delete;
  MediaStreamDevicesController& operator=(const MediaStreamDevicesController&) =
      delete;

  // Accept or deny the request based on the default policy.
  bool TakeAction();

  // Explicitly accept or deny the request.
  void Accept();
  void Deny(blink::mojom::MediaStreamRequestResult result);

 private:
  // Handle the request of desktop or tab screen cast.
  void HandleUserMediaRequest();

  // The original request for access to devices.
  const content::MediaStreamRequest request_;

  // The callback that needs to be Run to notify WebRTC of whether access to
  // audio/video devices was granted or not.
  content::MediaResponseCallback callback_;

  bool microphone_requested_;
  bool webcam_requested_;
};

}  // namespace electron

#endif  // SHELL_BROWSER_MEDIA_MEDIA_STREAM_DEVICES_CONTROLLER_H_
