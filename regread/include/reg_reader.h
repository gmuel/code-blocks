#ifndef REG_READER_H
#define REG_READER_H
#include <fstream>
#include <sstream>
#include <regex>
#include <list>
#include <filesystem>

namespace reg {

typedef std::ifstream           _ifs;
typedef std::stringstream       _ss;
typedef std::regex              _rex;
typedef std::string             _str;
typedef std::list<_str >        _lst;
typedef _lst::const_iterator    _clit;
typedef _lst::iterator          _lit;
typedef std::filesystem::path   _pth;

class reg_reader
{
    public:
        static const int DEF_SIZE = 1024;
        reg_reader(const _rex& rx, const _str& fileName, int sz = DEF_SIZE);
        reg_reader(const _rex& rx, const _pth& pth, int sz = DEF_SIZE);
        ~reg_reader();
        bool isGood() const;
        reg_reader& operator++();
        const _lst& operator*() const;
        void close() ;
        bool is_open() const ;
        void open(const _str& fl_nm) ;
        void open(const _pth& pth) ;
    protected:

    private:
    _lst mlst;
    _rex reg;
    _ss ss;
    _ifs is;
    int sz;
    void contRead();
    bool extractMatch(std::smatch& sm, const _str& tmp);

};

}

#endif // REG_READER_H
