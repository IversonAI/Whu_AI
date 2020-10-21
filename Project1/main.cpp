#include "Triangle.hpp"
#include "rasterizer.hpp"
#include <Eigen/eigen3/Eigen/Eigen>
#include <iostream>
#include <opencv2/opencv.hpp>

constexpr double MY_PI = 3.1415926;

Eigen::Matrix4f get_view_matrix(Eigen::Vector3f eye_pos)
{
	Eigen::Matrix4f view = Eigen::Matrix4f::Identity();

	Eigen::Matrix4f translate;
	translate << 1, 0, 0, -eye_pos[0], 0, 1, 0, -eye_pos[1], 0, 0, 1,
		-eye_pos[2], 0, 0, 0, 1;

	view = translate * view;

	return view;
}

Eigen::Matrix4f get_model_matrix(float rotation_angle)
{
	Eigen::Matrix4f model = Eigen::Matrix4f::Identity();

	Eigen::Matrix4f translate;
	translate << cos(rotation_angle / 180.0f * MY_PI), -sin(rotation_angle / 180.0f * MY_PI), 0, 0,
		sin(rotation_angle / 180.0f * MY_PI), cos(rotation_angle / 180.0f * MY_PI), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1;
	model = translate * model;
	// TODO: Implement this function
	// Create the model matrix for rotating the triangle around the Z axis.
	// Then return it.

	return model;
}

Eigen::Matrix4f get_model_matrix_arbitrary(float rotation_angle, float a, float b, float c)
{
	Eigen::Matrix4f model = Eigen::Matrix4f::Identity();

	Eigen::Matrix4f translate;
	translate << a * a*(1 - cos(rotation_angle / 180 * MY_PI)) + cos(rotation_angle / 180 * MY_PI), a*b*(1 - cos(rotation_angle / 180 * MY_PI)) + c * sin(rotation_angle / 180 * MY_PI), a*c*(1 - cos(rotation_angle / 180 * MY_PI)) - b * sin(rotation_angle / 180 * MY_PI), 0,
		a*b*(1 - cos(rotation_angle / 180 * MY_PI)) - c * sin(rotation_angle / 180 * MY_PI), b*b*(1 - cos(rotation_angle / 180 * MY_PI)) + cos(rotation_angle / 180 * MY_PI), c*b*(1 - cos(rotation_angle / 180 * MY_PI)) + a * sin(rotation_angle / 180 * MY_PI), 0,
		a*c*(1 - cos(rotation_angle / 180 * MY_PI)) + b * sin(rotation_angle / 180 * MY_PI), c*b*(1 - cos(rotation_angle / 180 * MY_PI)) - a * sin(rotation_angle / 180 * MY_PI), c*c*(1 - cos(rotation_angle / 180 * MY_PI)) + cos(rotation_angle / 180 * MY_PI), 0,
		0, 0, 0, 1;
	model = translate * model;
	// TODO: Implement this function
	// Create the model matrix for rotating the triangle around the Z axis.
	// Then return it.

	/*float x = axis[0];
    float y = axis[1];
    float z = axis[2];
    float norm = sqrt(x * x + y * y + z * z);
    float n_x = x / norm;
    float n_y = y / norm;
    float n_z = z / norm;
    Vector3f n_axis(n_x, n_y, n_z);
    
    float radian = angle * MY_PI / 180.0;
    float sinr = sin(radian);
    float cosr = cos(radian);

    Eigen::Matrix3f I = Eigen::Matrix3f::Identity();
    
    Eigen::Matrix3f N;
    N << 0.0, -n_z, n_y, \
        n_z, 0.0, -n_x, \
        -n_y, n_x, 0.0;

    model.block(0, 0, 3, 3) = cosr * I + (1 - cosr) * n_axis * n_axis.transpose() + sinr * N;*/
	return model;
}

Eigen::Matrix4f get_projection_matrix(float eye_fov, float aspect_ratio,
	float zNear, float zFar)
{
	// Students will implement this function

	Eigen::Matrix4f projection = Eigen::Matrix4f::Identity();

	Eigen::Matrix4f tmp;
	tmp << zNear, 0, 0, 0,
		0, zNear, 0, 0,
		0, 0, zNear + zFar, -zNear * zFar,
		0, 0, 1, 0;
	Eigen::Matrix4f ortho1, ortho2;
	float  r, t;
	t = zNear * tan(eye_fov / 2.0f / 180.0f * MY_PI);
	r = t * aspect_ratio;
	ortho1 << 1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, -(zNear + zFar) / 2,
		0, 0, 0, 1;
	ortho2 << 1 / r, 0, 0, 0,
		0, 1 / t, 0, 0,
		0, 0, 2 / (zNear - zFar), 0,
		0, 0, 0, 1;
	projection = ortho2 * ortho1*tmp;
	// TODO: Implement this function
	// Create the projection matrix for the given parameters.
	// Then return it.

	return projection;
}

int main(int argc, const char** argv)
{
	float angle = 0;
	bool command_line = false;
	std::string filename = "output.png";


	if (argc >= 3) {

		//std::cout << argv[1];
		angle = std::stof(argv[2]); // -r by default
		//std::cout << argv[2];
		command_line = true;


		if (argc == 4) {
			filename = std::string(argv[3]);
		}
		/*else
			return 0;*/
		if (argc > 4)
			command_line = false;
	}


	rst::rasterizer r(700, 700);

	Eigen::Vector3f eye_pos = { 0, 0, 5 };

	std::vector<Eigen::Vector3f> pos{ {2, 0, -2}, {0, 2, -2}, {-2, 0, -2} };

	std::vector<Eigen::Vector3i> ind{ {0, 1, 2} };

	auto pos_id = r.load_positions(pos);
	auto ind_id = r.load_indices(ind);

	int key = 0;
	int frame_count = 0;

	if (command_line) {
		r.clear(rst::Buffers::Color | rst::Buffers::Depth);

		r.set_model(get_model_matrix(angle));
		r.set_view(get_view_matrix(eye_pos));
		r.set_projection(get_projection_matrix(45, 1, 0.1, 50));

		r.draw(pos_id, ind_id, rst::Primitive::Triangle);
		cv::Mat image(700, 700, CV_32FC3, r.frame_buffer().data());
		image.convertTo(image, CV_8UC3, 1.0f);

		cv::imwrite(filename, image);

		return 0;
	}

	while (key != 27) {
		r.clear(rst::Buffers::Color | rst::Buffers::Depth);

		r.set_model(get_model_matrix(angle));
		if (argc > 4)
			r.set_view(get_model_matrix_arbitrary(angle, std::stof(argv[4]), std::stof(argv[5]), std::stof(argv[6])));
		else
			r.set_view(get_view_matrix(eye_pos));
		r.set_projection(get_projection_matrix(45, 1, 0.1, 50));

		r.draw(pos_id, ind_id, rst::Primitive::Triangle);

		cv::Mat image(700, 700, CV_32FC3, r.frame_buffer().data());
		image.convertTo(image, CV_8UC3, 1.0f);
		cv::imshow("image", image);
		key = cv::waitKey(10);

		std::cout << "frame count: " << frame_count++ << '\n';

		if (key == 'a') {
			angle += 10;
		}
		else if (key == 'd') {
			angle -= 10;
		}
	}

	return 0;
}
