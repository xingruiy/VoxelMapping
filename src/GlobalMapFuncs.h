#pragma once
#include "MapStruct.h"
#include <Eigen/Core>
#include <sophus/se3.hpp>
#include <opencv2/opencv.hpp>

namespace voxelization
{

    int FuseImage(
        MapStruct map,
        const cv::cuda::GpuMat depth,
        const Sophus::SE3d &camToWorld,
        const Eigen::Matrix3f &K);

    void ProjectRenderingBlocks(
        MapStruct map,
        uint count_visible_block,
        uint &count_rendering_block,
        cv::cuda::GpuMat &zrange_x,
        cv::cuda::GpuMat &zrange_y,
        RenderingBlock *listRenderingBlock,
        const Sophus::SE3f &worldToCam,
        const Eigen::Matrix3f &K);

    void RenderScene(
        MapStruct map,
        cv::cuda::GpuMat vmap,
        cv::cuda::GpuMat zRangeX,
        cv::cuda::GpuMat zRangeY,
        const Sophus::SE3f &camToWorld,
        const Eigen::Matrix3f &K);

    void Polygonize(
        MapStruct map,
        uint &block_count,
        uint &triangle_count,
        void *vertex_out,
        void *normal_out,
        size_t bufferSize = 0);

} // namespace voxelization