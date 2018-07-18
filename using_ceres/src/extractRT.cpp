#include <cmath>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>

#include <Eigen/Dense>

#include <ceres/jet.h>
#include <ceres/ceres.h>
#include <glog/logging.h>

using ceres::AutoDiffCostFunction;
using ceres::CostFunction;
using ceres::Problem;
using ceres::Solver;
using ceres::Solve;

class ICP_functor{
public:
	ICP_functor(const Eigen::Vector3d x_source, 
				const Eigen::Vector3d x_target):
				x_source_(x_source),
				x_target_(x_target){}

	template <typename T> 
	bool operator()(const T* const x,
					const T* const y,
					const T* const z,
					const T* const roll,
					const T* const pitch,
					const T* const yaw,
					T* residual) const {
		const T sin_theta = ceres::sin(theta[0]);
		const T cos_theta = ceres::cos(theta[0]);

		const T x_src[] = {(T)x_source_(0), (T)x_source_(1), (T)x_source_(2)};
		const T x_tgt[] = {(T)x_target_(0), (T)x_target_(1), (T)x_target_(2)};

		residual[0] = x_src[0] - cos_theta*x_tgt[0] - sin_theta*x_tgt[2] - x[0];
		residual[1] = x_src[1] - x_tgt[1];
		residual[2] = x_src[2] + sin_theta*x_tgt[0] - cos_theta*x_tgt[2] - z[0];
		return true;
	}

private:
		const Eigen::Vector3d x_source_;
		const Eigen::Vector3d x_target_;
};

int main(int argc, char** argv) {
    std::cout << "Hello World" << std::endl;
    return 0;
}