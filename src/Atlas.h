//
// Created by yb on 2024/4/30.
//

#ifndef PVZ_ATLAS_H
#define PVZ_ATLAS_H
#include <vector>
#include <easyx.h>
#include <memory>

class Atlas {
public:
    using SP=std::shared_ptr<Atlas>;
    Atlas()=default;
    ~Atlas();
public:
    void loadFromFile(LPCTSTR path,int num);
    void loadFromFile2(LPCTSTR path,int num);
    void clear();
    int getSize();
    IMAGE*getImage(int idx);
    void addImage(const IMAGE&img);
private:
    std::vector<IMAGE>m_imgList;
};


#endif //PVZ_ATLAS_H
