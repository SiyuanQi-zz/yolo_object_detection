#ifndef EXAMPLES_H
#define EXAMPLES_H

#ifdef __cplusplus
extern "C" {
#endif

void predict_classifier(char *datacfg, char *cfgfile, char *weightfile, char *filename, int top);
void test_detector(char *datacfg, char *cfgfile, char *weightfile, char *filename, float thresh, float hier_thresh, char *outfile, int fullscreen);
void run_voxel(int argc, char **argv);
void run_yolo(int argc, char **argv);
void run_detector(int argc, char **argv);
void run_coco(int argc, char **argv);
void run_writing(int argc, char **argv);
void run_captcha(int argc, char **argv);
void run_nightmare(int argc, char **argv);
void run_dice(int argc, char **argv);
void run_compare(int argc, char **argv);
void run_classifier(int argc, char **argv);
void run_regressor(int argc, char **argv);
void run_segmenter(int argc, char **argv);
void run_char_rnn(int argc, char **argv);
void run_vid_rnn(int argc, char **argv);
void run_tag(int argc, char **argv);
void run_cifar(int argc, char **argv);
void run_go(int argc, char **argv);
void run_art(int argc, char **argv);
void run_super(int argc, char **argv);
void run_lsd(int argc, char **argv);

#ifdef __cplusplus
}
#endif

#endif /* EXAMPLES_H */
