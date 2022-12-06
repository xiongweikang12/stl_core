#ifndef hashfunction_special_base
#define hashfunction_special_base

inline size_t __stl_hash_string(const char* s)
{
	unsigned long n = 0;
	for (; *s; ++s)
	{
		n = 5 * n + *s;
	}
	return size_t(n);
}

#endif // !char_hashfunction
