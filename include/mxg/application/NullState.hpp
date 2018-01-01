// Copyright (C) 2017 Emerson Max de Medeiros Silva
//
// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
// OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
// OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef MXG_APPLICATION_NULLSTATE_HPP_
#define MXG_APPLICATION_NULLSTATE_HPP_

#include "mxg/application/DefaultState.hpp"

namespace mxg {
namespace application {

class NullState : public DefaultState {
    public:
        static NullState& getInstance() {
            static NullState instance;
            return instance;
        }

        NullState(const NullState&) = delete;
        void operator=(const NullState&) = delete;

    private:
        NullState() = default;
};

} /* namespace application */
} /* namespace mxg */
#endif /* MXG_APPLICATION_NULLSTATE_HPP_ */