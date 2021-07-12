#pragma once
#include <memory>
#include <Eigen/Core>
#include <sophus/se3.hpp>
#include <opencv2/opencv.hpp>

namespace voxelization
{
  class Voxelization
  {
  public:
    Voxelization(int w, int h, const Eigen::Matrix3f &K);
    ~Voxelization();

    void reset();
    void FuseDepth(cv::cuda::GpuMat depth, const Sophus::SE3d &camToWorld);
    void RenderScene(cv::cuda::GpuMat &vmap, const Sophus::SE3d &camToWorld);
    int Polygonize(float *&verts_out, float *&norms_out);

  protected:
    struct VoxelizationImpl;
    std::unique_ptr<VoxelizationImpl> impl;
  };

} // namespace voxelization