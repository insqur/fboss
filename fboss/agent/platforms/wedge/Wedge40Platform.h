/*
 *  Copyright (c) 2004-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */
#pragma once

#include "fboss/agent/platforms/wedge/WedgePlatform.h"

namespace facebook { namespace fboss {

class BcmSwitch;
class WedgePort;
class WedgeProductInfo;

class Wedge40Platform : public WedgePlatform {
 public:
  explicit Wedge40Platform(std::unique_ptr<WedgeProductInfo> productInfo) :
    WedgePlatform(std::move(productInfo)) {}
  Wedge40Platform(std::unique_ptr<WedgeProductInfo> productInfo,
                uint8_t numQsfps) : WedgePlatform(std::move(productInfo),
                  numQsfps) {}

  InitPortMap initPorts() override;

  folly::ByteRange defaultLedCode() override;


 private:
  Wedge40Platform(Wedge40Platform const &) = delete;
  Wedge40Platform& operator=(Wedge40Platform const &) = delete;
};

}} // namespace facebook::fboss
