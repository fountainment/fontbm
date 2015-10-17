#pragma once
#include <string>
#include <vector>
#include <sstream>

// http://www.angelcode.com/products/bmfont/doc/file_format.html

struct Font
{
    struct Info
    {
        struct Padding
        {
            std::string toString() const
            {
                std::stringstream ss;
                ss << static_cast<int>(up)
                    << "," << static_cast<int>(right)
                    << "," << static_cast<int>(down)
                    << "," << static_cast<int>(left);
                return ss.str();
            }

            uint8_t up;
            uint8_t right;
            uint8_t down;
            uint8_t left;
        };

        struct Spacing
        {
            std::string toString() const
            {
                std::stringstream ss;
                ss << static_cast<int>(horizontal) << "," << static_cast<int>(vertical);
                return ss.str();
            }
            uint8_t horizontal;
            uint8_t vertical;
        };

        std::string toString() const
        {
            std::stringstream ss;
            ss << "face=\"" << face << "\""
                << " size=" << static_cast<int>(size)
                << " bold=" << bold
                << " italic=" << italic
                << " charset=\"" << static_cast<int>(charset) << "\""
                << " unicode=" << unicode
                << " stretchH=" << static_cast<int>(stretchH)
                << " smooth=" << smooth
                << " aa=" << static_cast<int>(aa)
                << " padding=" << padding.toString()
                << " spacing=" << spacing.toString()
                << " outline=" << static_cast<int>(outline);
            return ss.str();
        }

        uint16_t size;
        bool smooth;
        bool unicode;
        bool italic;
        bool bold;
        bool fixedHeigth;
        uint8_t charset;
        uint16_t stretchH;
        uint8_t aa;
        Padding padding;
        Spacing spacing;
        uint8_t outline;
        std::string face;
    };

    struct Common
    {
        std::string toString() const
        {
            std::stringstream ss;
            ss << "lineHeight=" << lineHeight
                << " base=" << base
                << " scaleW=" << scaleW
                << " scaleH=" << scaleH
                << " pages=" << pages
                << " packed=" << packed
                << " alphaChnl=" << alphaChnl
                << " redChnl=" << redChnl
                << " greenChnl=" << greenChnl
                << " blueChnl=" << blueChnl;
            return ss.str();
        }

        uint16_t lineHeight;
        uint16_t base;
        uint16_t scaleW;
        uint16_t scaleH;
        uint16_t pages;      //TODO: duplicate std::vector<Page> pages
        bool packed;
        uint8_t alphaChnl;
        uint8_t redChnl;
        uint8_t greenChnl;
        uint8_t blueChnl;
    };

    struct Char
    {
        std::string toString() const
        {
            std::stringstream ss;
            ss << "id=" << id
                << " x=" << x
                << " y=" << y
                << " width=" << width
                << " height=" << height
                << " xoffset=" << xoffset
                << " yoffset=" << yoffset
                << " xadvance=" << xadvance
                << " page=" << page
                << " chnl=" << chnl;
            return ss.str();
        }

        uint32_t id;
        uint16_t x;
        uint16_t y;
        uint16_t width;
        uint16_t height;
        int16_t xoffset;
        int16_t yoffset;
        int16_t xadvance;
        uint8_t page;
        uint8_t chnl;
    };

    struct Kerning
    {
        std::string toString() const
        {
            std::stringstream ss;
            ss << "first=" << first << " second=" << second << " amount=" << amount;
            return ss.str();
        }

        uint32_t first;
        uint32_t second;
        int16_t amount;
    };

    Info info;
    Common common;
    std::vector<std::string> pages;
    std::vector<Char> chars;
    std::vector<Kerning> kernings;

    void debugFillValues();
    void writeToXmlFile(const std::string &fileName) const;
    void writeToTextFile(const std::string &fileName) const;
    void writeToBinFile(const std::string &fileName) const;
};
