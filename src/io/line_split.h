/*!
 *  Copyright (c) 2015 by Contributors
 * \file line_split.h
 * \brief base class implementation of input splitter
 * \author Tianqi Chen
 */
#ifndef DMLC_IO_LINE_SPLIT_H_
#define DMLC_IO_LINE_SPLIT_H_

#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <dmlc/io.h>
#include "./input_split_base.h"

namespace dmlc {
namespace io {
/*! \brief class that split the files by line */
class LineSplitter : public InputSplitBase {
 public:
  LineSplitter(FileSystem *fs,
               const char *uri,
               unsigned rank,
               unsigned nsplit) {
    this->Init(fs, uri, rank, nsplit, 1);
  }

 protected:
  virtual size_t SeekRecordBegin(Stream *fi);
  virtual const char*
  FindLastRecordBegin(const char *begin, const char *end);
  virtual char* FindNextRecord(char *begin, char *end);
};
}  // namespace io
}  // namespace dmlc
#endif  // DMLC_IO_LINE_SPLIT_H_
