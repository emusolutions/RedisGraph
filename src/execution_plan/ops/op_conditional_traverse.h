/*
* Copyright 2018-2020 Redis Labs Ltd. and Contributors
*
* This file is available under the Redis Labs Source Available License Agreement
*/

#pragma once

#include "op.h"
#include "shared/traverse_functions.h"
#include "../execution_plan.h"
#include "../../arithmetic/algebraic_expression.h"
#include "../../../deps/GraphBLAS/Include/GraphBLAS.h"

/* OP Traverse */
typedef struct {
	OpBase op;
	Graph *graph;
	AlgebraicExpression *ae;
	GrB_Matrix F;               // Filter matrix.
	GrB_Matrix M;               // Algebraic expression result.
	NodeID dest_label_id;       // ID of destination node label if known.
	const char *dest_label;     // Label of destination node if known.
	EdgeTraverseCtx *edge_ctx;  // Edge collection data if the edge needs to be set.
	GxB_MatrixTupleIter iter;  // Iterator over M.
	int srcNodeIdx;             // Source node index into record.
	int destNodeIdx;            // Destination node index into record.
	uint record_count;          // Number of held records.
	uint record_cap;            // Max number of records to process.
	Record *records;            // Array of records.
	Record r;                   // Currently selected record.
} OpCondTraverse;

/* Creates a new Traverse operation */
OpBase *NewCondTraverseOp(const ExecutionPlan *plan, Graph *g, AlgebraicExpression *ae);

