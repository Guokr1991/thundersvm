//
// Created by jiashuai on 17-9-17.
//

#ifndef THUNDERSVM_DATASET_H
#define THUNDERSVM_DATASET_H

#include "thundersvm.h"
#include "syncdata.h"
class DataSet {
public:
    struct node{
        node(int index, real value):index(index), value(value){}
        int index;
        real value;
    };
    typedef vector<vector<DataSet::node>> node2d;
    DataSet();
    void load_from_file(string file_name);
    size_t total_count() const;
    size_t n_features() const;
    size_t n_classes() const;
    const int* count() const;
    const int* start() const;
    const int* label() const;
    const node2d & instances() const;
    const node2d instances(int y_i) const;
    const node2d instances(int y_i, int y_j) const;

private:
    void group_classes();
    vector<int> y_;
    node2d instances_;
    size_t total_count_;
    size_t n_features_;
    vector<int> start_;
    vector<int> count_;
    vector<int> label_;
    vector<int> perm_;
};
#endif //THUNDERSVM_DATASET_H
