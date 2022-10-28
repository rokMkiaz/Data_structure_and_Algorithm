#pragma once

template<typename T>
class DisjointSet
{
public:
	struct Set;

public:
	static Set* CreateSet(T data)
	{
		Set* set = new Set();
		set->Parent = NULL;

		return set;
		
	}
	static void DestroySet(Set* set)
	{
		delete set;
		set = NULL;
	}

	static Set* FindSet(Set* set) //그룹위치
	{
		while (set->Parent != NULL)
			set = set->Parent;
		return set;
	}

	static void UnionSet(Set* parent, Set* set)
	{
		set = FindSet(set);
		set->Parent = parent;
	}

public:
	struct Set
	{
		T data;
		Set* Parent;
	};
};