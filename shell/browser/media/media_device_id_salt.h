// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SHELL_BROWSER_MEDIA_MEDIA_DEVICE_ID_SALT_H_
#define SHELL_BROWSER_MEDIA_MEDIA_DEVICE_ID_SALT_H_

#include <string>

#include "components/prefs/pref_member.h"

class PrefRegistrySimple;
class PrefService;

namespace electron {

// MediaDeviceIDSalt is responsible for creating and retrieving a salt string
// that is used for creating MediaSource IDs that can be cached by a web
// service. If the cache is cleared, the  MediaSourceIds are invalidated.
class MediaDeviceIDSalt {
 public:
  explicit MediaDeviceIDSalt(PrefService* pref_service);
  ~MediaDeviceIDSalt();

  // disable copy
  MediaDeviceIDSalt(const MediaDeviceIDSalt&) = delete;
  MediaDeviceIDSalt& operator=(const MediaDeviceIDSalt&) = delete;

  std::string GetSalt();

  static void RegisterPrefs(PrefRegistrySimple* pref_registry);
  static void Reset(PrefService* pref_service);

 private:
  StringPrefMember media_device_id_salt_;
};

}  // namespace electron

#endif  // SHELL_BROWSER_MEDIA_MEDIA_DEVICE_ID_SALT_H_
