#ifndef OPENPOSE_FILESTREAM_TEXT_OFSTREAM_HPP
#define OPENPOSE_FILESTREAM_TEXT_OFSTREAM_HPP

#include <fstream> // std::ofstream
#include <openpose/core/common.hpp>

namespace op
{
    class OP_API TextOfstream
    {
    public:
        explicit TextOfstream(const std::string& filePath, const bool humanReadable = true);

        ~TextOfstream();

        /*void objectOpen();

        void objectClose();

        void arrayOpen();

        void arrayClose();

        void version(const std::string& version);

        void key(const std::string& string);
		*/
        template <typename T>
        inline void plainText(const T& value)
        {
            mOfstream << value;
        }

        inline void comma()
        {
            mOfstream << ",";
        }
		//enter
		inline void huiche()
		{
			mOfstream << "\n";
		}
  //      void enter();

    private:
        const bool mHumanReadable;
        long long mBracesCounter;
        long long mBracketsCounter;
        std::ofstream mOfstream;

        DELETE_COPY(TextOfstream);
    };
}

#endif // OPENPOSE_FILESTREAM_TEXT_OFSTREAM_HPP
