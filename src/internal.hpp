// Include catch {{{
#ifdef _MSC_VER
#pragma once
#endif

#ifndef _fsm_internal_hpp_
#define _fsm_internal_hpp_
// }}}

#include <assert.h>

#ifdef FSM_ASSERT
#undef FSM_ASSERT
#endif

#define FSM_ASSERT( X ) assert( X )
#define FSM_ASSERT_FAIL() assert(false)

#endif
