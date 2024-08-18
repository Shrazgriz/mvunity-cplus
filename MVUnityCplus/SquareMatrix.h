#pragma once
#include <string>
#include <vector>
#include <sstream>
#include "V3.h"
using namespace std;

namespace MVUnity {
	class SquareMatrix
	{
	protected:
		/// <summary>
		/// 是否已计算特征值
		/// </summary>
		bool _computeEigens;
		/// <summary>
		/// 特征值
		/// </summary>
		vector<double> _eigenValues;
		/// <summary>
		/// 特征向量
		/// </summary>
		vector<V3> _eigenVectors;
	public:
		/// <summary>
		/// 
		/// </summary>
		int Size;
		/// <summary>
		/// [Row,Col]
		/// </summary>
		double** Elements;

		/// <summary>
		/// Default constructor, size=1
		/// </summary>
		SquareMatrix()
		{
			Size = 1;
			Elements = new double* [1];
			Elements[0] = new double[1];
			_computeEigens = false;
		}
		/// <summary>
		/// 
		/// </summary>
		/// <param name="size"></param>
		SquareMatrix(int size)
		{
			Size = size;
			_computeEigens = false;
			Elements = new double* [Size];
			for (int i = 0; i < Size; i++)
			{
				Elements[i] = new double[Size];
			}
		}
		/// <summary>
		/// Duplicate a new square matrix
		/// </summary>
		/// <param name="AnotherMatrix"></param>
		SquareMatrix(const SquareMatrix& AnotherMatrix)
		{
			Size = AnotherMatrix.Size;
			_computeEigens = AnotherMatrix._computeEigens;
			Elements = new double* [Size];
			for (int i = 0; i < Size; i++)
			{
				Elements[i] = new double[Size];
				memcpy(Elements[i], AnotherMatrix.Elements[i], Size);
			}
		}
		/// <summary>
		/// Get column
		/// </summary>
		/// <param name="columnIndex"></param>
		/// <returns></returns>
		double* operator [](int columnIndex)
		{
			return Elements[columnIndex];
		}
		/// <summary>
		/// Switch one column, useful for solving linear equations
		/// </summary>
		/// <param name="columnnum"></param>
		/// <param name="newcolumn"></param>
		void SwitchColumn(int columnnum, const double newcolumn[])
		{
			for (int i = 0; i < Size; i++)
			{
				Elements[i][columnnum] = newcolumn[i];
			}
		}
		/// <summary>
		/// C*M
		/// </summary>
		/// <param name="factor"></param>
		/// <returns></returns>
		SquareMatrix operator *(const double factor)
		{
			SquareMatrix result = SquareMatrix(Size);
			for (int i = 0; i < Size; i++)
			{
				for (int j = 0; j < Size; j++)
				{
					result.Elements[i][j] = factor * this->Elements[i][j];
				}
			}
			return result;
		}
		/// <summary>
		/// Remove 1 col and 1 row, get a sub-matrix
		/// </summary>
		/// <param name="row"></param>
		/// <param name="column"></param>
		/// <returns></returns>
		SquareMatrix SubMatrix(int row, int column)
		{
			SquareMatrix sub = SquareMatrix(Size - 1);
			int i, j;
			for (i = 0; i < row; i++)
				for (j = 0; j < column; j++)
					sub.Elements[i][j] = Elements[i][j];

			for (i = row; i < Size - 1; i++)
				for (j = 0; j < column; j++)
					sub.Elements[i][j] = Elements[i + 1][j];

			for (i = 0; i < row; i++)
				for (j = column; j < Size - 1; j++)
					sub.Elements[i][j] = Elements[i][j + 1];

			for (i = row; i < Size - 1; i++)
				for (j = column; j < Size - 1; j++)
					sub.Elements[i][j] = Elements[i + 1][j + 1];
			return sub;
		}
		/// <summary>
		/// Algebraic sub matrix
		/// </summary>
		/// <param name="row"></param>
		/// <param name="column"></param>
		/// <returns></returns>
		SquareMatrix AlgebraicSub(int row, int column)
		{
			SquareMatrix sub = SubMatrix(row, column);
			if ((row + column) % 2 == 0) return sub;
			else return sub * (-1);
		}

		/// <summary>
		/// Value of determinat
		/// </summary>
		/// <returns></returns>
		double Determinant()
		{
			if (Size == 2) return Elements[0][0] * Elements[1][1] - Elements[1][0] * Elements[0][1];
			else
			{
				double result = 0;
				for (int i = 0; i < Size; i++)
				{
					SquareMatrix sub = SubMatrix(Size - 1, i);
					if ((Size - 1 + i) % 2 == 0) result += Elements[Size - 1][i] * sub.Determinant();
					else result -= Elements[Size - 1][i] * sub.Determinant();
				}
				return result;
			}
		}
		/// <summary>
		/// Write in string
		/// </summary>
		/// <param name="Format"></param>
		/// <returns></returns>
		string ToString()
		{
			stringstream ss;
			std::string output;
			ss << "Square Matrix size :{0}\n\r" << Size;
			for (int i = 0; i < Size; i++)
			{
				for (int j = 0; j < Size; j++)
				{
					ss << this[j][i] << ",";
				}
				ss << "\n\r";
			}
			ss >> output;
			return output;
		}

		/// <summary>
		/// 转置
		/// </summary>
		/// <param name="Input"></param>
		/// <returns></returns>
		static SquareMatrix Transpose(SquareMatrix Input)
		{
			SquareMatrix result = SquareMatrix(Input.Size);
			for (int i = 0; i < Input.Size; i++)
			{
				for (int j = 0; j < Input.Size; j++)
				{
					result[i][j] = Input[j][i];
				}
			}
			return result;
		}
		/// <summary>
		/// 相同尺寸的方阵加法
		/// </summary>
		/// <param name="rhs"></param>
		/// <returns></returns>
		/// <exception cref="Exception"></exception>
		SquareMatrix operator +(const SquareMatrix& rhs)
		{
			if (Size != rhs.Size) throw "方阵尺寸不同, SquareMatrix + 运算";
			SquareMatrix result = SquareMatrix(Size);
			for (int i = 0; i < Size; i++)
			{
				for (int j = 0; j < Size; j++)
				{
					result.Elements[i][j] = this->Elements[i][j] + rhs.Elements[i][j];
				}
			}
			return result;
		}
	};
}
