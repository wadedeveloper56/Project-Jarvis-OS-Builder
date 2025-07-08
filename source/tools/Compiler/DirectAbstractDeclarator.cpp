#include "DirectAbstractDeclarator.h"

using namespace WadeSpace;

DirectAbstractDeclarator::DirectAbstractDeclarator(AbstractDeclarator& ad) :ad(ad) {}
DirectAbstractDeclarator::DirectAbstractDeclarator() :ad(std::nullopt) {}
DirectAbstractDeclarator::~DirectAbstractDeclarator() {}
AbstractDeclarator& DirectAbstractDeclarator::getAd() const { return ad->get(); }
