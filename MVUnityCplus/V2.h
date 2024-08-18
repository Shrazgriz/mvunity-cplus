#pragma once
#include <string>
#include <vector>
#include <sstream>

namespace MVUnity {
	/// <summary>
	/// ��ά����
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
			std::vector<std::string> results; // �����洢���
			std::string str; //��������ÿ���ָ���ַ���
			// ��ʼ�ָ�
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
		/// ���
		/// </summary>
		/// <param name="vector"></param>
		/// <returns></returns>
		double Dot(V2 vector)
		{
			return X * vector.X + Y * vector.Y;
		}
		/// <summary>
		/// ���
		/// </summary>
		/// <param name="vector"></param>
		/// <returns></returns>
		double Cross(V2 vector)
		{
			return (X * vector.Y) - (Y * vector.X);
		}
		/// <summary>
		/// �����ӷ�
		/// </summary>
		/// <param name="vector2"></param>
		/// <returns></returns>
		V2 operator +(const V2& vector)
		{
			V2 ret = V2(X + vector.X, Y + vector.Y);
			return ret;
		}
		/// <summary>
		/// ��������
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
		/// �������
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
		/// XY������С��
		/// </summary>
		/// <param name="vector1"></param>
		/// <param name="vector2"></param>
		/// <returns></returns>
		bool operator <(const V2& vector)
		{
			return (X < vector.X) && (Y < vector.Y);
		}
		/// <summary>
		/// XY����������
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
		/// �������ƽ��ֵ
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
		/// ������ƽ������תָ���Ƕ�
		/// </summary>
		/// <param name="AngleInRad">�Ի��ȼƵĽǶ�</param>
		/// <returns></returns>
		V2 Rotate(double AngleInRad)
		{
			return V2((X * cos(AngleInRad)) - (Y * sin(AngleInRad)), (X * sin(AngleInRad)) + (Y * cos(AngleInRad)));
		}
		/// <summary>
		/// ������ʸ����x��н���ת����
		/// </summary>
		/// <param name="Direction">����ʸ��</param>
		/// <returns></returns>
		V2 Rotate(V2 Direction)
		{
			V2 _d = Direction.Normalized();
			return V2((X * _d.X) - (Y * _d.Y), (X * _d.Y) + (Y * _d.X));
		}
		/// <summary>
		/// ��ת45��
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
		/// ��ת45��
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
		/// ��ȡ������x��нǻ���,��0~2Pi����
		/// </summary>
		/// <param name="Vec">������</param>
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
		/// ��ȡ������y��нǻ���
		/// </summary>
		/// <param name="Vec">������</param>
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
		/// ת������
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
		/// ������תֱ������
		/// </summary>
		/// <param name="Polar"></param>
		/// <returns></returns>
		static V2 ToXY(V2 Polar)
		{
			V2 mod = V2(Polar.X, 0);
			return mod.Rotate(Polar.Y);
		}
		/// <summary>
		/// ƽ���������
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
