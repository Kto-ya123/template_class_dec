#include"dec.h"
#include<conio.h>
#include<iostream>
namespace my
{
	/*template<typename type> void dec<type>::ev_del_tw()
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
		
	}
	*/
	/*
	template<typename type> dec<type>::dec()
	{
		_begin = new list;
		_end = _begin;
		_begin->lptr = NULL;
		_begin->rptr = NULL;
	}
	template<typename type> typename dec<type>::iterator dec<type>::begin() const { return _begin; };
	template<typename type> typename dec<type>::iterator dec<type>::end() const { return _end; };
	template<typename type> void dec<type>::push_back(type val)
	{
		_end->value = val;
		_end->rptr = new list;
		_end->rptr->lptr = _end;
		_end = _end->rptr;
		_end->rptr = NULL;
	}
	template<typename type> void dec<type>::push_front(type val)
	{
		_begin->lptr = new list;
		_begin->lptr->rptr = _begin;
		_begin = _begin->lptr;
		_begin->value = val;
		_begin->lptr = NULL;
	}
	template<typename type> type dec<type>::pop_back()
	{
		if (empty())
		{
			return INT_MIN;
		}
		list* del = _end;
		_end = _end->lptr;
		_end->rptr = NULL;
		delete del;
		return _end->value;
	}
	template<typename type> type dec<type>::pop_front()
	{
		if (empty())
		{
			return INT_MIN;
		}
		int val = _begin->value;
		list* del = _begin;
		_begin = _begin->rptr;
		_begin->lptr = NULL;
		delete del;
		return val;
	}
	template<typename type> bool dec<type>::empty()const
	{
		return (_begin == _end);
	}
	template<typename type> dec<type>::dec(const dec<type>& copy_dec) :dec()
	{
		if (copy_dec.empty())
			return;
		for (list* pl(copy_dec._begin); pl != copy_dec._end; pl = pl->rptr)
		{
			push_back(pl->value);
		}
	}
	template<typename type> dec<type>::~dec()
	{
		while (_end != NULL)
		{
			list* del_el = _end;
			_end = _end->lptr;
			delete del_el;
		}
	}
	template<typename type> const dec<type>& dec<type>::operator=(const dec& copy_dec)
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
	template<typename type> size_t dec<type>::size()const
	{
		size_t i(0);
		for (list* pl(_begin); pl != _end; pl = pl->rptr)
			i++;
		return i;
	}
	template<typename type> bool dec<type>::operator==(const dec& rav_dec)const
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
	template<typename type> type& dec<type>::operator[](int& a) const
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
	*/
	/*template<typename type> dec_iterator<type>::dec_iterator() :pl(NULL) {}
	template<typename type> dec_iterator<type>::dec_iterator(const dec_iterator<type>& cplt) : pl(cplt.pl) {}
	template<typename type> dec_iterator<type>::dec_iterator(list* const& cplt) : pl(cplt) {}
	template<typename type> dec_iterator<type> dec_iterator<type>::operator=(const dec_iterator<type>& cpl) { pl = cpl.pl; return *this; }
	template<typename type> dec_iterator<type>& dec_iterator<type>::operator++() { pl = pl->rptr; return *this; };
	template<typename type> dec_iterator<type> dec_iterator<type>::operator++(int) { dec_iterator<type> it = *this; ++*this; return it; }
	template<typename type> dec_iterator<type>& dec_iterator<type>::operator--() { pl = pl->lptr; return *this; }
	template<typename type> dec_iterator<type> dec_iterator<type>::operator--(int) { dec_iterator<type> it = *this; --*this; return it; }
	template<typename type> type& dec_iterator<type>::operator*() { return pl->value; }
	template<typename type> type& dec_iterator<type>::operator[](int a)
	{
		list* sch = pl;
		for (int i(0); i < a; i++)
		{
			sch = sch->rptr;
		}
		return sch->value;
	}
	template<typename type> dec_iterator<type> dec_iterator<type>::operator+(int a)const
	{
		dec_iterator ret = *this;
		for (int i(0); i < a; i++)
			ret.pl = ret.pl->rptr;
		return ret;
	}
	template<typename type> dec_iterator<type> dec_iterator<type>::operator-(int a)const
	{
		dec_iterator ret = *this;
		for (int i(0); i < a; i++)
			ret.pl = ret.pl->lptr;
		return ret;
	}
	template<typename type> bool dec_iterator<type>::operator != (const dec_iterator<type>& rav_it)const{ if (pl == rav_it.pl)return false; return true; }
	*/
}