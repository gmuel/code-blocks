#include "../include/reg_reader.h"
namespace reg {
reg_reader::reg_reader(const _rex& rx, const _str& fl_nm, int ssz):
mlst(),reg(rx),ss(),is(fl_nm.c_str()),sz(ssz)
{
    //ctor
}
reg_reader::reg_reader(const _rex& rx, const _pth& pth, int ssz):
mlst(),reg(rx),ss(),is(pth),sz(ssz)
{
    //ctor
}
reg_reader::~reg_reader()
{
    close();
}

bool reg_reader::isGood() const
{
    return is.is_open() &&
        ! is.bad() &&
            ! is.fail() &&
                ! is.eof();
}

reg_reader& reg_reader::operator++()
{
    contRead();
    return *this;
}

const _lst& reg_reader::operator*() const
{
    return mlst;
}
void reg_reader::close()
{
    if(is.is_open()) {
        is.close();
    }
}
void reg_reader::contRead()
{
    char line[sz];
    while(isGood())
    {
        is.read(line,sz);
        ss << line;
    }
    std::smatch sm;
    extractMatch(sm,ss.str());
}

bool reg_reader::extractMatch(std::smatch& sm, const _str& tmp)
{
    unsigned int lsz = mlst.size();
    while(std::regex_search(tmp,sm,reg))
    {
        const _str& mtch = sm.str(0);
		mlst.push_back(mtch);
//		unsigned int pos = sm.position(0) + mtch.length();
//		if(pos<tmp.length()) ss.str(tmp.substr(pos));
//		else ss.str("");
//		return true;
    }
    return lsz!=mlst.size();
}

bool reg_reader::is_open() const
{
    return is.is_open();
}
void reg_reader::open(const _str& fl_name) {
    close();
    this->is.open(fl_name);
}
void reg_reader::open(const _pth& pth) {
    close();
    this->is.open(pth);
}
}
