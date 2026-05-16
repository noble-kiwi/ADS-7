// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
    Car* node = new Car;
    node->light = light;

    if (first == nullptr) {
        first = node;
        first->next = first;
        first->prev = first;
    } else {
        Car* tail = first->prev;
        tail->next = node;
        node->prev = tail;
        node->next = first;
        first->prev = node;
    }
}

int Train::getLength() {
    if (first == nullptr) return 0;

    first->light = true;
    Car* cursor = first;
    int steps_forward = 0;

    while (true) {
        cursor = cursor->next;
        steps_forward++;
        countOp++;

        if (cursor->light) {
            cursor->light = false;

            Car* inspector = cursor;
            for (int i = 0; i < steps_forward; i++) {
                inspector = inspector->prev;
                countOp++;
            }

            if (!inspector->light) {
                return steps_forward;
            }

            cursor = inspector;
            for (int j = 0; j < steps_forward; j++) {
                cursor = cursor->next;
                countOp++;
            }
        }
    }
}

int Train::getOpCount() {
    return countOp;
}
