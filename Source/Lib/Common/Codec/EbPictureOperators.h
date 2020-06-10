/*
* Copyright(c) 2019 Intel Corporation
* SPDX - License - Identifier: BSD - 2 - Clause - Patent
*/

#ifndef EbPictureOperators_h
#define EbPictureOperators_h

#include "EbPictureOperators_C.h"
#include "EbDefinitions.h"
#include "EbPictureBufferDesc.h"
#ifdef __cplusplus
extern "C" {
#endif

extern EbErrorType picture_full_distortion32_bits(
    EbPictureBufferDesc *coeff, uint32_t coeff_luma_origin_index,
    uint32_t coeff_chroma_origin_index, EbPictureBufferDesc *recon_coeff,
    uint32_t recon_coeff_luma_origin_index, uint32_t recon_coeff_chroma_origin_index,
    uint32_t bwidth, uint32_t bheight, uint32_t bwidth_uv, uint32_t bheight_uv,
    uint64_t y_distortion[DIST_CALC_TOTAL], uint64_t cb_distortion[DIST_CALC_TOTAL],
    uint64_t cr_distortion[DIST_CALC_TOTAL], uint32_t y_count_non_zero_coeffs,
    uint32_t cb_count_non_zero_coeffs, uint32_t cr_count_non_zero_coeffs,
    COMPONENT_TYPE component_type);
//Residual Data

void compressed_pack_sb(uint8_t *in8_bit_buffer, uint32_t in8_stride, uint8_t *inn_bit_buffer,
                        uint32_t inn_stride, uint16_t *out16_bit_buffer, uint32_t out_stride,
                        uint32_t width, uint32_t height);

void pack2d_src(uint8_t *in8_bit_buffer, uint32_t in8_stride, uint8_t *inn_bit_buffer,
                uint32_t inn_stride, uint16_t *out16_bit_buffer, uint32_t out_stride,
                uint32_t width, uint32_t height);

void un_pack2d(uint16_t *in16_bit_buffer, uint32_t in_stride, uint8_t *out8_bit_buffer,
               uint32_t out8_stride, uint8_t *outn_bit_buffer, uint32_t outn_stride, uint32_t width,
               uint32_t height);

static INLINE void memset16bit(uint16_t *in_ptr, uint16_t value, uint64_t num_of_elements) {
    uint64_t i;

    for (i = 0; i < num_of_elements; i++) in_ptr[i] = value;
}

static INLINE void memset32bit(uint32_t *in_ptr, uint32_t value, uint64_t num_of_elements) {
    uint64_t i;

    for (i = 0; i < num_of_elements; i++) in_ptr[i] = value;
}

void full_distortion_kernel_cbf_zero32_bits_c(int32_t *coeff, uint32_t coeff_stride,
                                              uint64_t distortion_result[DIST_CALC_TOTAL],
                                              uint32_t area_width, uint32_t area_height);

void full_distortion_kernel32_bits_c(int32_t *coeff, uint32_t coeff_stride, int32_t *recon_coeff,
                                     uint32_t recon_coeff_stride,
                                     uint64_t distortion_result[DIST_CALC_TOTAL],
                                     uint32_t area_width, uint32_t area_height);

uint64_t full_distortion_kernel16_bits_c(uint8_t *input, uint32_t input_offset,
                                         uint32_t input_stride, uint8_t *pred, int32_t pred_offset,
                                         uint32_t pred_stride, uint32_t area_width,
                                         uint32_t area_height);

void residual_kernel16bit_c(uint16_t *input, uint32_t input_stride, uint16_t *pred,
                            uint32_t pred_stride, int16_t *residual, uint32_t residual_stride,
                            uint32_t area_width, uint32_t area_height);

void residual_kernel8bit_c(uint8_t *input, uint32_t input_stride, uint8_t *pred,
                           uint32_t pred_stride, int16_t *residual, uint32_t residual_stride,
                           uint32_t area_width, uint32_t area_height);

void picture_addition_kernel16_bit(uint16_t *pred_ptr, uint32_t pred_stride, int32_t *residual_ptr,
                                   uint32_t residual_stride, uint16_t *recon_ptr,
                                   uint32_t recon_stride, uint32_t width, uint32_t height,
                                   int32_t bd);

void pic_copy_kernel_8bit(EbByte src, uint32_t src_stride, EbByte dst, uint32_t dst_stride,
                          uint32_t area_width, uint32_t area_height);

void pic_copy_kernel_16bit(uint16_t *src, uint32_t src_stride, uint16_t *dst, uint32_t dst_stride,
                           uint32_t width, uint32_t height);

EbErrorType picture_copy(EbPictureBufferDesc *src, uint32_t src_luma_origin_index,
                         uint32_t src_chroma_origin_index, EbPictureBufferDesc *dst,
                         uint32_t dst_luma_origin_index, uint32_t dst_chroma_origin_index,
                         uint32_t area_width, uint32_t area_height, uint32_t chroma_area_width,
                         uint32_t chroma_area_height, uint32_t component_mask, uint8_t hbd);

#ifdef __cplusplus
}
#endif
#endif // EbPictureOperators_h
