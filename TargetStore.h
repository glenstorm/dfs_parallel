#ifndef _TARGET_STORE_H_GUARD_
#define _TARGET_STORE_H_GUARD_

// Store parallel array with mutable Target objects
class TargetStore
{
public:
	explicit TargetStore(size_t vertexes_num)
	{
		vertex2Target_.resize( vertexes_num );
	}

	void add( size_t id )
	{
		vertex2Target_[id] = Target( id );
	}

	Target& operator[]( size_t id )
	{
		return vertex2Target_[id];
	}

	const Target& operator[]( size_t id ) const
	{
		return vertex2Target_[id];
	}

private:
	std::vector<Target> vertex2Target_;
};


#endif
	// _TARGET_STORE_H_GUARD_
