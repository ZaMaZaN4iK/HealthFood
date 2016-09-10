//
// Created by zamazan4ik on 09.09.16.
//

#ifndef COOKER_COMPOSITION_HPP
#define COOKER_COMPOSITION_HPP

struct Composition
{
    double fat_, carbohydr_, prot_;

    Composition(){}

    Composition(const double fat, const double carbo, const double prot) :
            fat_(fat), carbohydr_(carbo), prot_(prot)
    {}

};

#endif //COOKER_COMPOSITION_HPP
