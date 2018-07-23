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

// class ICP_functor{
// public:
// 	ICP_functor(const Eigen::Vector3d x_source, 
// 				const Eigen::Vector3d x_target):
// 				x_source_(x_source),
// 				x_target_(x_target){}

// 	template <typename T> 
// 	bool operator()(const T* const x,
// 					const T* const y,
// 					const T* const z,
// 					const T* const roll,
// 					const T* const pitch,
// 					const T* const yaw,
// 					T* residual) const {
// 		const T sin_theta = ceres::sin(theta[0]);
// 		const T cos_theta = ceres::cos(theta[0]);

// 		const T x_src[] = {(T)x_source_(0), (T)x_source_(1), (T)x_source_(2)};
// 		const T x_tgt[] = {(T)x_target_(0), (T)x_target_(1), (T)x_target_(2)};

// 		residual[0] = x_src[0] - cos_theta*x_tgt[0] - sin_theta*x_tgt[2] - x[0];
// 		residual[1] = x_src[1] - x_tgt[1];
// 		residual[2] = x_src[2] + sin_theta*x_tgt[0] - cos_theta*x_tgt[2] - z[0];
// 		return true;
// 	}

// private:
// 		const Eigen::Vector3d x_source_;
// 		const Eigen::Vector3d x_target_;
// };
void storePoints(std::vector<Eigen::Vector3d> &XYZ, 
				 std::string file_name) {
	std::string line;
	std::ifstream myfile(file_name);
	if (myfile.is_open()) {
		while (myfile.good()) {
			getline(myfile, line);
			std::istringstream iss(line);
			std::string word;
			int i = 0;
			while(iss >> word) {
				std::string::size_type sz;
				std::string word_;
				double arr[4];
				int count = 0;
				for (int j = 0; j < word.size(); j++) {

					if(word[j] == ',') {
						std::string::size_type sz;
						double number = std::stod(word_, &sz);
						arr[count++] = number;
						word_.clear();
						continue;
					} else {
						word_ = word_ + word[j];
					}
				}
				XYZ.push_back(Eigen::Vector3d(arr[0], arr[1], arr[2]));
			}
		}
	}	
}

int main(int argc, char** argv) {
	std::string file_name1 = "../data/XYZi.txt";
	std::string file_name2 = "../data/XYZj.txt";
	std::vector<Eigen::Vector3d> XYZi, XYZj;
	storePoints(XYZi, file_name1);
	storePoints(XYZj, file_name2);
    return 0;
}