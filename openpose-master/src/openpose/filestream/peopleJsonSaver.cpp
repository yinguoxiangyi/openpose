#include <openpose/filestream/fileStream.hpp>
#include <openpose/filestream/peopleJsonSaver.hpp>

namespace op
{
    PeopleJsonSaver::PeopleJsonSaver(const std::string& directoryPath) :
        FileSaver{directoryPath}
    {
    }

    void PeopleJsonSaver::save(const std::vector<std::pair<Array<float>, std::string>>& keypointVector,
                               const std::vector<std::vector<std::array<float,3>>>& candidates,
                               const std::string& fileName, const bool humanReadable) const
    {
        try
        {
            /*// Record json
            const auto finalFileName = getNextFileName(fileName) + ".json";
			savePeopleJson(keypointVector, candidates, finalFileName, humanReadable);*/
			const auto finalFileName = getNextFileName("out_data") + ".txt";;//设置输出文件名
			savePeopleText(keypointVector, candidates, finalFileName, humanReadable);
        }
        catch (const std::exception& e)
        {
            error(e.what(), __LINE__, __FUNCTION__, __FILE__);
        }
    }
}
