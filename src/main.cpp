#include <pybind11/pybind11.h>

#include <stdio.h>
#include "rnnoise.h"
#include <iostream>

//using namespace std;
#ifndef TRAINING
#define TRAINING 0
#endif

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

int add(int i, int j) {
    return i + j;
}

int main(int argc, char **argv)
{
  if(TRAINING){
    train(argc, argv);
    return 0;
  }
  FILE *f1, *fout;
  DenoiseState *st;
  st = rnnoise_create();
  if (argc!=3) {
    fprintf(stderr, "usage: %s <noisy speech> <output denoised>\n", argv[0]);
    return 1;
  }
  f1 = fopen(argv[1], "rb");
  fout = fopen(argv[2], "wb");
  rnnoise_destroy(st);
  fclose(f1);
  fclose(fout);
  return 0;
}

namespace py = pybind11;

PYBIND11_MODULE(_py_webrtcrnnvad, m) {
    m.doc() = R"pbdoc(
        py_webrtcrnnvad
        -----------------------
        .. currentmodule:: py_webrtcrnnvad
        .. autosummary::
           :toctree: _generate
           add
           subtract
    )pbdoc";

    py::class_<DenoiseState>(m, "DenoiseState");

    m.def("rnnoise_create", &rnnoise_create, R"pbdoc(
        Create noiseState instance
    )pbdoc");

    m.def("rnnvad_process_npframe", &rnnvad_process_npframe, R"pbdoc(
        process audio frame and returns vad prob
    )pbdoc");

    m.def("rnnoise_destroy", &rnnoise_destroy, R"pbdoc(
        destroy noiseState instance
    )pbdoc");

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}