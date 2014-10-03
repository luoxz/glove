#ifndef RENDERING_VERTEX_MANAGEDINDEXDATA_H_
#define RENDERING_VERTEX_MANAGEDINDEXDATA_H_

#include <vector>

#include "rendering/vertex/IndexData.h"

namespace glove {

/** 
 * Represents managed index data.
 * This class adds and additional RAM buffer for indices for fast and easy read-backs.
 */
class ManagedIndexData : public IndexData {
	GLOVE_MEM_ALLOC_FUNCS("ManagedIndexData")
public:
	/** The index list type */
	typedef std::vector<unsigned int> IndexList;

	ManagedIndexData();
	virtual ~ManagedIndexData();

	/** Returns the internal (RAM) list of indices */
	virtual const IndexList& GetIndices() const { return indices; }
	/** Sets the internal (RAM) list of indices but does not automatically update the GPU buffer */
	virtual void SetIndices(IndexList indexList) { indices = indexList; }

	/** Returns the number of indices in the RAM buffer */
	virtual const size_t GetIndexCount() const { return indices.size(); }
	/** NoOp */
	virtual void SetIndexCount(size_t count) { }

	/** Uploads the RAM buffer to the GPU */
	virtual void FlushBuffer() const;

protected:
	IndexList indices;
};


} // namespace glove

#endif