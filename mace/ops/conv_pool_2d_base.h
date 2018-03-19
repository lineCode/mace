//
// Copyright (c) 2017 XiaoMi All rights reserved.
//

#ifndef MACE_OPS_CONV_POOL_2D_BASE_H_
#define MACE_OPS_CONV_POOL_2D_BASE_H_

#include <vector>

#include "mace/core/operator.h"
#include "mace/kernels/conv_pool_2d_util.h"

namespace mace {
namespace ops {

template <DeviceType D, class T>
class ConvPool2dOpBase : public Operator<D, T> {
 public:
  ConvPool2dOpBase(const OperatorDef &op_def, Workspace *ws)
      : Operator<D, T>(op_def, ws),
        strides_(OperatorBase::GetRepeatedArgument<int>("strides")),
        padding_type_(static_cast<Padding>(OperatorBase::GetSingleArgument<int>(
            "padding", static_cast<int>(SAME)))),
        paddings_(OperatorBase::GetRepeatedArgument<int>("padding_values")),
        dilations_(
            OperatorBase::GetRepeatedArgument<int>("dilations", {1, 1})) {}

 protected:
  std::vector<int> strides_;
  Padding padding_type_;
  std::vector<int> paddings_;
  std::vector<int> dilations_;
};

}  // namespace ops
}  // namespace mace

#endif  // MACE_OPS_CONV_POOL_2D_BASE_H_
