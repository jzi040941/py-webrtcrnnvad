#ifndef NNET_DATA_H
#define NNET_DATA_H

#include "nnet.h"

typedef struct RNNModel {
  int input_dense_size;
  const DenseLayer *input_dense;

  int vad_gru_size;
  const GRULayer *vad_gru;

  int noise_gru_size;
  const GRULayer *noise_gru;

  int denoise_gru_size;
  const GRULayer *denoise_gru;

  int denoise_output_size;
  const DenseLayer *denoise_output;

  int vad_output_size;
  const DenseLayer *vad_output;
}RNNModel;

typedef struct RNNState {
  const RNNModel *model;
  float *vad_gru_state;
  float *noise_gru_state;
  float *denoise_gru_state;
} RNNState;


#endif