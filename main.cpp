#include "opencv2/ccalib/randpattern.hpp"
#include "opencv2/opencv.hpp"

using namespace cv;

const char * usage =
    "\n example command line for generating a random pattern. \n"
    "   random_patterng_generator -iw 600 -ih 850 pattern.png\n"
    "\n";

static void help()
{
    printf("\n This is a sample for generating a random pattern that can be used for calibration.\n"
        "Usage: random_patterng_generator\n"
        "    -iw <image_width> # the width of pattern image\n"
        "    -ih <image_height> # the height of pattern image\n"
        "    filename # the filename for pattern image \n"
        );
    printf("\n %s", usage);
}

cv::Mat gen_avatar()
{
    cv::theRNG().state = static_cast<uint64>(1145141919810+time(0));
    Mat pattern;
    int width = 0, height = 0;

    height = 1024;
    width = 1024;

    randpattern::RandomPatternGenerator generator(width, height);
    generator.generatePattern();
    pattern = generator.getPattern();
    return pattern;
}

int main(int argc, char const *argv[])
{
    int to_color = 22;
    while (1) {
        cv::Mat pattern = gen_avatar();
        if (to_color < 22) {
           cv::applyColorMap(pattern, pattern, to_color); 
        }
        // cv::applyColorMap(pattern, pattern, cv::COLORMAP_CIVIDIS);
        cv::imshow("pattern", pattern);
        auto key = cv::waitKey(0);
        if (key == 's') {
            cv::imwrite("avatar.png", pattern);
        } else if (key == 'd') {
            to_color += 1;
            to_color %= 23;
        } else if (key == 'q') {
            break;
        }
    }
    return 0;
}
