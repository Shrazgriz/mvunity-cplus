#pragma once
#include <string>
#include <vector>
#include <sstream>

namespace MVUnity {
	/// <summary>
	/// 二维向量
	/// </summary>
	class V2
	{
	private:

	public:
		/// <summary>
			/// Component X
			/// </summary>
		double X;
		/// <summary>
		/// Component Y
		/// </summary>
		double Y;
		/// <summary>
		/// Create new V2 with component X and Y
		/// </summary>
		/// <param name="x"></param>
		/// <param name="y"></param>
		V2(double x, double y)
		{
			X = x;
			Y = y;
		}

		/// <summary>
		/// Duplicate a V2
		/// </summary>
		/// <param name="point"></param>
		V2(const V2& point)
		{
			X = point.X;
			Y = point.Y;
		}
		/// <summary>
		/// Convert string into V2
		/// </summary>
		/// <param name="ValueString"></param>
		/// <param name="spliter"></param>
		V2(std::string ValueString, char spliter = ',')
		{
			std::stringstream ss(ValueString);
			std::vector<std::string> results; // 用来存储结果
			std::string str; //用来接收每个分割的字符串
			// 开始分隔
			while (getline(ss, str, spliter)) {
				results.push_back(str);
			}
			if (results.size() != 2)
			{
				X = 0;
				Y = 0;
			}
			else
			{
				X = std::stod(results[0]);
				Y = std::stod(results[1]);
			}
		}
		/// <summary>
		/// Express V2 to string
		/// </summary>
		virtual std::string ToString()
		{
			std::stringstream ss;
			std::string exp;
			ss << X << "," << Y;
			ss >> exp;
			return exp;
		}

		/// <summary>
		/// Mod of V2, sqrt(x^2+y^2)
		/// </summary>
		double Mod() {
			return sqrt((X * X) + (Y * Y));
		}
		/// <summary>
		/// 点乘
		/// </summary>
		/// <param name="vector"></param>
		/// <returns></returns>
		double Dot(V2 vector)
		{
			return X * vector.X + Y * vector.Y;
		}
		/// <summary>
		/// 叉乘
		/// </summary>
		/// <param name="vector"></param>
		/// <returns></returns>
		double Cross(V2 vector)
		{
			return (X * vector.Y) - (Y * vector.X);
		}
		/// <summary>
		/// 向量加法
		/// </summary>
		/// <param name="vector2"></param>
		/// <returns></returns>
		V2 operator +(const V2& vector)
		{
			V2 ret = V2(X + vector.X, Y + vector.Y);
			return ret;
		}
		/// <summary>
		/// 向量减法
		/// </summary>
		/// <param name="vec1"></param>
		/// <param name="vec2"></param>
		/// <returns></returns>
		V2 operator -(const V2& vector)
		{
			return V2(X - vector.X, Y - vector.Y);
		}
		/// <summary>
		/// V2*number
		/// </summary>
		/// <param name="vector"></param>
		/// <param name="factor"></param>
		/// <returns></returns>
		V2 operator *(const double factor)
		{
			return V2(X * factor, Y * factor);
		}
		/// <summary>
		/// 向量点乘
		/// </summary>
		/// <param name="vector"></param>
		/// <returns></returns>
		double operator *(const V2& vector)
		{
			return (X * vector.X) + (Y * vector.Y);
		}
		/// <summary>
		/// number*V2
		/// </summary>
		/// <param name="factor"></param>
		/// <param name="vector"></param>
		/// <returns></returns>
		V2 operator *(const int factor)
		{
			return V2(X * factor, Y * factor);
		}
		/// <summary>
		/// V2/number
		/// </summary>
		/// <param name="vector"></param>
		/// <param name="divisor"></param>
		/// <returns></returns>
		V2 operator /(const double divisor)
		{
			return V2(X / divisor, Y / divisor);
		}
		/// <summary>
		/// 
		/// </summary>
		/// <param name="vector1"></param>
		/// <param name="vector2"></param>
		/// <returns></returns>
		bool operator ==(const V2& vector)
		{
			return (X == vector.X) && (Y == vector.Y);
		}
		/// <summary>
		/// 
		/// </summary>
		/// <param name="vector"></param>
		/// <returns></returns>
		bool operator !=(const V2& vector)
		{
			return (X != vector.X) || (Y != vector.Y);
		}
		/// <summary>
		/// XY分量均小于
		/// </summary>
		/// <param name="vector1"></param>
		/// <param name="vector2"></param>
		/// <returns></returns>
		bool operator <(const V2& vector)
		{
			return (X < vector.X) && (Y < vector.Y);
		}
		/// <summary>
		/// XY分量均大于
		/// </summary>
		/// <param name="vector1"></param>
		/// <param name="vector2"></param>
		/// <returns></returns>
		bool operator >(const V2& vector2)
		{
			return (X > vector2.X) && (Y > vector2.Y);
		}
		/// <summary>
		/// Euclidean distance
		/// </summary>
		/// <param name="P"></param>
		/// <returns></returns>
		double Distance(V2 P)
		{
			return sqrt(((P.X - X) * (P.X - X)) + ((P.Y - Y) * (P.Y - Y)));
		}
		/// <summary>
		/// 两点距离平方值
		/// </summary>
		/// <param name="P"></param>
		/// <param name="Q"></param>
		/// <returns></returns>
		static double DistSquare(V2 P, V2 Q)
		{
			return ((P.X - Q.X) * (P.X - Q.X)) + ((P.Y - Q.Y) * (P.Y - Q.Y));
		}
		/// <summary>
		/// Manhattan distance
		/// </summary>
		/// <param name="p1"></param>
		/// <param name="p2"></param>
		/// <returns></returns>
		static double Manhattan(V2 p1, V2 p2)
		{
			return abs(p1.X - p2.X) + abs(p1.Y - p2.Y);
		}
		/// <summary>
		/// Manhattan distance
		/// </summary>
		/// <param name="X1"></param>
		/// <param name="Y1"></param>
		/// <param name="X2"></param>
		/// <param name="Y2"></param>
		/// <returns></returns>
		static double Manhattan(double X1, double Y1, double X2, double Y2)
		{
			return abs(X1 - X2) + abs(Y1 - Y2);
		}
		/// <summary>
		/// Get normalized vector, this/|this|
		/// </summary>
		V2 Normalized()
		{
			double r = sqrt((X * X) + (Y * Y));
			return V2(X / r, Y / r);
		}

		/// <summary>
		/// 向量在平面内旋转指定角度
		/// </summary>
		/// <param name="AngleInRad">以弧度计的角度</param>
		/// <returns></returns>
		V2 Rotate(double AngleInRad)
		{
			return V2((X * cos(AngleInRad)) - (Y * sin(AngleInRad)), (X * sin(AngleInRad)) + (Y * cos(AngleInRad)));
		}
		/// <summary>
		/// 按方向矢量与x轴夹角旋转向量
		/// </summary>
		/// <param name="Direction">方向矢量</param>
		/// <returns></returns>
		V2 Rotate(V2 Direction)
		{
			V2 _d = Direction.Normalized();
			return V2((X * _d.X) - (Y * _d.Y), (X * _d.Y) + (Y * _d.X));
		}
		/// <summary>
		/// 旋转45度
		/// </summary>
		/// <param name="Value"></param>
		/// <returns></returns>
		static V2 Rotate45(V2 Value)
		{
			double a = Value.X * COS_45;
			double b = Value.Y * COS_45;
			return V2(a - b, a + b);
		}
		/// <summary>
		/// 旋转45度
		/// </summary>
		/// <param name="x"></param>
		/// <param name="y"></param>
		/// <returns></returns>
		static V2 Rotate45(double x, double y)
		{
			double a = x * COS_45;
			double b = y * COS_45;
			return V2(a - b, a + b);
		}
		/// <summary>
		/// 获取向量与x轴夹角弧度,在0~2Pi区间
		/// </summary>
		/// <param name="Vec">弧度制</param>
		/// <returns></returns>
		static double GetTheta(V2 Vec)
		{
			double m = Vec.Mod();
			if (m == 0)
			{
				return 0;
			}
			double cos = Vec.X / m;
			double theta = acos(cos);
			if (Vec.Y < 0)
			{
				theta = (M_PI * 2) - theta;
			}

			return theta;
		}
		/// <summary>
		/// 获取向量与y轴夹角弧度
		/// </summary>
		/// <param name="Vec">弧度制</param>
		/// <returns></returns>
		static double GetTheta2YAxis(V2 Vec)
		{
			double m = Vec.Mod();
			if (m == 0)
			{
				return 0;
			}
			double cos = Vec.Y / m;
			double theta = acos(cos);
			if (Vec.X > 0)
			{
				theta = M_PI * 2 - theta;
			}
			return theta;
		}
		/// <summary>
		/// 转极坐标
		/// </summary>
		/// <param name="XY"></param>
		/// <returns></returns>
		static V2 ToPolar(V2 XY)
		{
			if (XY.Mod() == 0)
			{
				return V2(0, 0);
			}
			double theta = GetTheta(XY);
			return V2(XY.Mod(), theta);
		}
		/// <summary>
		/// 极坐标转直角坐标
		/// </summary>
		/// <param name="Polar"></param>
		/// <returns></returns>
		static V2 ToXY(V2 Polar)
		{
			V2 mod = V2(Polar.X, 0);
			return mod.Rotate(Polar.Y);
		}
		/// <summary>
		/// 平面向量叉乘
		/// </summary>
		/// <param name="Vec1"></param>
		/// <param name="Vec2"></param>
		/// <returns></returns>
		static double Cross(V2 Vec1, V2 Vec2)
		{
			return (Vec1.X * Vec2.Y) - (Vec1.Y * Vec2.X);
		}
	};

	/// <summary>
	/// Zero vector (0,0)
	/// </summary>
	static const V2 Zero = V2(0, 0);

	/// <summary>
	/// Right vector (1,0)
	/// </summary>
	static const V2 Right = V2(1, 0);
	/// <summary>
	/// Up vector (0,1)
	/// </summary>
	static const V2 Up = V2(0, 1);
	/// <summary>
	/// (1,1)
	/// </summary>
	static const V2 Identity = V2(1, 1);
}
