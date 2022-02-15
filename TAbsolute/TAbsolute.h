//
// Created by Matthew Li on 2/15/22.
//

#ifndef TABSOLUTE_TABSOLUTE_H
#define TABSOLUTE_TABSOLUTE_H

namespace TAbsoluteLi
{
    template<class T>
    class TAbsolute
    {
    public:
        T absolute(T a, T b);
        T frequent(T a[], std::size_t size);
    };
}// TAbsoluteLi
#endif
