//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef TOOLS_HPP_
# define TOOLS_HPP_

namespace tools
{
	template <typename T>
	class v3
	{
	public:
		v3(T x, T y, T z) : x(x), y(y), z(z) {}
		v3() {}
		~v3(){}
		void operator=(v3<T> right)
		{
			this->x = right.x;
			this->y = right.y;
			this->z = right.z;
		}
	T x;
	T y;
	T z;
	};

        template <typename T>
        class v2
        {
        public:
		v2(T x, T y) : x(x), y(y) {}
		v2() {}
		~v2() {};
		void operator=(v2<T> right)
		{
			this->x = right.x;
			this->y = right.y;
		}

        T x;
        T y;
        };

    template <typename T>
    class Info
    {
        public:
		Info() {}
		Info(const Info<T> &info)
		{
			this->_pos = info._pos;
			this->_dim = info._dim;
			this->_deg = info._deg;
		}
		Info(v3<T> pos, v3<T> dim, v3<T> deg)
		{
			_pos = pos;
			_dim = dim;
			_deg = deg;
		}
		~Info() {}

		void operator=(Info<T> info)
		{
			this->_pos = info._pos;
			this->_dim = info._dim;
			this->_deg = info._deg;
		}
        v3<T>  _pos;
        v3<T>  _dim;
        v3<T>  _deg;
        private:
    };
};

#endif /* !TOOLS_HPP_ */
