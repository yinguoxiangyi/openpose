#include <openpose/filestream/textOfstream.hpp>
#include <iostream>
namespace op
{
    void enterAndTab_1(std::ofstream& ofstream, const bool humanReadable, const long long bracesCounter,
                     const long long bracketsCounter)
    {
        try
        {
            if (humanReadable)
            {
                ofstream << "\n";
                for (auto i = 0ll ; i < bracesCounter + bracketsCounter ; i++)
                    ofstream << "\t";
            }
        }
        catch (const std::exception& e)
        {
            error(e.what(), __LINE__, __FUNCTION__, __FILE__);
        }
    }

    TextOfstream::TextOfstream(const std::string& filePath, const bool humanReadable) :
        mHumanReadable{humanReadable},
        mBracesCounter{0},
        mBracketsCounter{0},
        mOfstream{filePath , std::ios::app }//设置打开方式
    {
        try
        {
            if (!filePath.empty() && !mOfstream.is_open())
                error("Text file could not be opened.", __LINE__, __FUNCTION__, __FILE__);
        }
        catch (const std::exception& e)
        {
            error(e.what(), __LINE__, __FUNCTION__, __FILE__);
        }
    }

    TextOfstream::~TextOfstream()
    {
        try
        {
            enterAndTab_1(mOfstream, mHumanReadable, mBracesCounter, mBracketsCounter);

            if (mBracesCounter != 0 || mBracketsCounter != 0)
            {
                std::string errorMessage = "Text file wronly generated";
                if (mBracesCounter != 0)
                    errorMessage += ", number \"{\" != number \"}\": " + std::to_string(mBracesCounter) + ".";
                else if (mBracketsCounter != 0)
                    errorMessage += ", number \"[\" != number \"]\": " + std::to_string(mBracketsCounter) + ".";
                else
                    errorMessage += ".";
                error(errorMessage, __LINE__, __FUNCTION__, __FILE__);
            }
        }
        catch (const std::exception& e)
        {
            error(e.what(), __LINE__, __FUNCTION__, __FILE__);
        }
    }

    /*void TextOfstream::objectOpen()
    {
        try
        {
            mBracesCounter++;
            mOfstream << "{";
        }
        catch (const std::exception& e)
        {
            error(e.what(), __LINE__, __FUNCTION__, __FILE__);
        }
    }

    void TextOfstream::objectClose()
    {
        try
        {
            mBracesCounter--;
            enterAndTab(mOfstream, mHumanReadable, mBracesCounter, mBracketsCounter);
            mOfstream << "}";
        }
        catch (const std::exception& e)
        {
            error(e.what(), __LINE__, __FUNCTION__, __FILE__);
        }
    }

    void TextOfstream::arrayOpen()
    {
        try
        {
            mBracketsCounter++;
            mOfstream << "[";
            enterAndTab(mOfstream, mHumanReadable, mBracesCounter, mBracketsCounter);
        }
        catch (const std::exception& e)
        {
            error(e.what(), __LINE__, __FUNCTION__, __FILE__);
        }
    }

    void TextOfstream::arrayClose()
    {
        try
        {
            mBracketsCounter--;
            enterAndTab(mOfstream, mHumanReadable, mBracesCounter, mBracketsCounter);
            mOfstream << "]";
        }
        catch (const std::exception& e)
        {
            error(e.what(), __LINE__, __FUNCTION__, __FILE__);
        }
    }

    void TextOfstream::version(const std::string& version)
    {
        try
        {
            key("version");
            plainText(version);
        }
        catch (const std::exception& e)
        {
            error(e.what(), __LINE__, __FUNCTION__, __FILE__);
        }
    }

    void TextOfstream::key(const std::string& string)
    {
        try
        {
            enterAndTab(mOfstream, mHumanReadable, mBracesCounter, mBracketsCounter);
            mOfstream << "\"" + string + "\":";
        }
        catch (const std::exception& e)
        {
            error(e.what(), __LINE__, __FUNCTION__, __FILE__);
        }
    }

    void TextOfstream::enter()
    {
        try
        {
            enterAndTab(mOfstream, mHumanReadable, mBracesCounter, mBracketsCounter);
        }
        catch (const std::exception& e)
        {
            error(e.what(), __LINE__, __FUNCTION__, __FILE__);
        }
    }*/
}
