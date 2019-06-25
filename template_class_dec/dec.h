#pragma once

namespace my
{
	template<typename type> class dec_data;
	template<typename type> class dec;
	template<typename type> class dec_iterator
	{
	public:
		friend class dec<type>;
		typedef dec_data<type> list;
		/*
		dec_iterator();
		dec_iterator(list* const&);
		dec_iterator(const dec_iterator<type>&);
		dec_iterator operator=(const dec_iterator<type>&);
		dec_iterator& operator++();
		dec_iterator operator++(int);
		dec_iterator& operator--();
		dec_iterator operator--(int);
		dec_iterator operator+(int)const;
		dec_iterator operator-(int)const;
		type& operator[](int);
		type& operator*();
		bool operator != (const dec_iterator<type>&)const;
		*/
		dec_iterator() :pl(NULL) {}
		dec_iterator(const dec_iterator<type>& cplt) : pl(cplt.pl) {};
		dec_iterator(list* const& cplt) : pl(cplt) {};
		dec_iterator<type> operator=(const dec_iterator<type>& cpl) { pl = cpl.pl; return *this; };
		dec_iterator<type>& operator++() { pl = pl->rptr; return *this; };
		dec_iterator<type> operator++(int) { dec_iterator<type> it = *this; ++*this; return it; };
		dec_iterator<type>& operator--() { pl = pl->lptr; return *this; };
		dec_iterator<type> operator--(int) { dec_iterator<type> it = *this; --*this; return it; };
		const type& operator*()const { return pl->value; }
		type& operator*() { return pl->value; }
		
		const type& operator[](int a)const
		{
			list* sch = pl;
			for (int i(0); i < a; i++)
			{
				sch = sch->rptr;
			}
			return sch->value;
		}
		type& operator[](int a)
		{
			list* sch = pl;
			for (int i(0); i < a; i++)
			{
				sch = sch->rptr;
			}
			return sch->value;
		}
		dec_iterator<type> operator+(int a)const
		{
			dec_iterator ret = *this;
			for (int i(0); i < a; i++)
				ret.pl = ret.pl->rptr;
			return ret;
		}
		dec_iterator<type> operator-(int a)const
		{
			dec_iterator ret = *this;
			for (int i(0); i < a; i++)
				ret.pl = ret.pl->lptr;
			return ret;
		}
		bool operator != (const dec_iterator<type>& rav_it)const { if (pl == rav_it.pl)return false; return true; }

	private:
		list* pl;
	};


	template<typename type>class dec_data
	{
	public:
		friend class dec<type>;
		friend class dec_iterator<type>;
	private:
		dec_data<type>* lptr;
		dec_data<type>* rptr;
		type value;
	};


	template<typename type>class dec
	{
	public:
		
		friend class dec_iterator<type>;
		typedef dec_iterator<type> iterator;
		typedef dec_data<type> list;
		//конструкторы
		/*
		dec();
		dec(const dec<type>&);
		//итераторы
		iterator begin()const;
		iterator end()const;
		//операторы
		const dec& operator=(const dec&);
		bool operator==(const dec&)const;
		//size
		size_t size()const;
		//функции добавления
		void push_back(type);
		void push_front(type);
		//функции удаления
		type pop_back();
		type pop_front();
		//пустой
		bool empty()const;
		~dec();
		void ev_del_tw();
		type& operator[](int&) const;
		*/

		dec()
		{
			_begin = new list;
			_end = _begin;
			_begin->lptr = NULL;
			_begin->rptr = NULL;
		}
		dec(const dec<type>& copy_dec) :dec()
		{
			if (copy_dec.empty())
				return;
			for (list* pl(copy_dec._begin); pl != copy_dec._end; pl = pl->rptr)
			{
				push_back(pl->value);
			}
		}
		typename const dec<type>::iterator& begin() const { return _begin; };
		typename const dec<type>::iterator& end() const { return _end; };
		void push_back(type val)
		{
			_end->value = val;
			_end->rptr = new list;
			_end->rptr->lptr = _end;
			_end = _end->rptr;
			_end->rptr = NULL;
		}
		void push_front(type val)
		{
			_begin->lptr = new list;
			_begin->lptr->rptr = _begin;
			_begin = _begin->lptr;
			_begin->value = val;
			_begin->lptr = NULL;
		}
		type pop_back()
		{
			if (empty())
			{
				return 0;
			}
			list* del = _end;
			_end = _end->lptr;
			_end->rptr = NULL;
			delete del;
			return _end->value;
		}
		type pop_front()
		{
			if (empty())
			{
				return 0;
			}
			type val = _begin->value;
			list* del = _begin;
			_begin = _begin->rptr;
			_begin->lptr = NULL;
			delete del;
			return val;
		}
		bool empty()const
		{
			return (_begin == _end);
		}	
		~dec()
		{
			while (_end != NULL)
			{
				list* del_el = _end;
				_end = _end->lptr;
				delete del_el;
			}
		}
		const dec<type>& operator=(const dec& copy_dec)
		{
			while (copy_dec.size() < size())
				pop_back();
			while (copy_dec.size() > size())
				push_back(NULL);
			list* pl_1 = _begin;
			list* pl_2 = copy_dec._begin;
			while (pl_1 != _end)
			{
				pl_1->value = pl_2->value;
				pl_1 = pl_1->rptr;
				pl_2 = pl_2->rptr;
			}
			return *this;
		}
		size_t size()const
		{
			size_t i(0);
			for (list* pl(_begin); pl != _end; pl = pl->rptr)
				i++;
			return i;
		}
		bool operator==(const dec& rav_dec)const
		{
			if (rav_dec.size() != size())
				return false;
			for (list* pl_1(rav_dec._begin), *pl_2(_begin); pl_2 != _end;
				pl_1 = pl_1->rptr, pl_2 = pl_2->rptr)
			{
				if (pl_1->value != pl_1->value)
					return false;
			}
			return true;
		}
		type& operator[](const int& a)
		{
			if (a > size() - 1)
			{
				out_of_range a("out");
				throw a;
			}
		
			list* sch = _begin;
			for (int i(0); i != a; i++)
			{
				sch = sch->rptr;
			}
			return sch->value;
		}
		const type& operator[](const int& a) const
		{
			if (a > size() - 1)
				return a;
			list* sch = _begin;
			for (int i(0); i != a; i++)
			{
				sch = sch->rptr;
			}
			return sch->value;
		}
		void ev_del_tw()
		{
			if (empty())
				return;
			list* del_el = _begin;
			list* el = _begin;
			while (el->rptr != _end)
			{
				del_el = el->rptr;
				el->rptr = del_el->rptr;
				del_el->rptr->lptr = el;
				delete del_el;
				el = el->rptr;
				if (el == _end)
					return;
			}
			/*
			list* ptr = _begin;
			for (int i(0); i < _size / 2; i++)
			{
			list* del = ptr->rptr;
			ptr->rptr = del->rptr;
			ptr->rptr->lptr = ptr;
			ptr = ptr->rptr;
			delete del;
			}
			_size -= _size / 2;
			*/
		}
	private:
		list* _begin;
		list* _end;
	};
}