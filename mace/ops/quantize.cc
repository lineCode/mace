// Copyright 2018 Xiaomi, Inc.  All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "mace/ops/quantize.h"

namespace mace {
namespace ops {

void Register_Quantize(OperatorRegistry *op_registry) {
  MACE_REGISTER_OPERATOR(op_registry, OpKeyBuilder("Quantize")
                                          .Device(DeviceType::CPU)
                                          .TypeConstraint<uint8_t>("T")
                                          .Build(),
                         QuantizeOp<DeviceType::CPU, uint8_t>);
}

void Register_Dequantize(OperatorRegistry *op_registry) {
  MACE_REGISTER_OPERATOR(op_registry, OpKeyBuilder("Dequantize")
                                          .Device(DeviceType::CPU)
                                          .TypeConstraint<uint8_t>("T")
                                          .Build(),
                         DequantizeOp<DeviceType::CPU, uint8_t>);
}

void Register_Requantize(OperatorRegistry *op_registry) {
  MACE_REGISTER_OPERATOR(op_registry, OpKeyBuilder("Requantize")
                                          .Device(DeviceType::CPU)
                                          .TypeConstraint<uint8_t>("T")
                                          .Build(),
                         RequantizeOp<DeviceType::CPU, uint8_t>);
}

}  // namespace ops
}  // namespace mace
