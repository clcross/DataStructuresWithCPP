#ifdef QUADTREE_H__
#include <iostream>

QuadTree::QuadTree(float width, float height) {
    this->width = width;
    this->height = height;
    Root = NULL;
}

QuadTree::~QuadTree() {
}

bool QuadTree::add(QNode *node, float x, float y, float sx, float sy, float ex, float ey) {
    float midx = (ex-sx)/2.0;
    float midy = (ey-sy)/2.0;

    if (node->is_leaf()) {
        // First we move the point to the correct quadrant
        if (node->x < midx && node->y < midy) {
            node->tl = new QNode(node->x, node->y);
        } else if (node->x < midx && node->y >= midy) {
            node->bl = new QNode(node->x, node->y);
        } else if (node->x >= midx && node->y < midy) {
            node->tr = new QNode(node->x, node->y);
        } else {
            node->br = new QNode(node->x, node->y);
        }
    }

    if (x < midx && y < midy) {
        if (node->tl == NULL) {
            node->tl = new QNode(x, y);
        } else {
            return add(node->tl, x, y, sx, sy, midx, midy);
        }
    } else if (x < midx && y >= midy) {
        if (node->bl == NULL) {
            node->bl = new QNode(x, y);
        } else {
            return add(node->bl, x, y, sx, midy, midx, ey);
        }
    } else if (x >= midx && y < midy) {
        if (node->tr == NULL) {
            node->tr = new QNode(x, y);
        } else {
            return add(node->tr, x, y, midx, sy, ex, midy);
        }
    } else {
        if (node->br == NULL) {
            node->br = new QNode(x, y);
        } else {
            return add(node->br, x, y, midx, midy, ex, ey);
        }
    }

    return true;
}

// ASSUME (0, 0) is the upper left!
bool QuadTree::add(float x, float y) {
    if (Root == NULL) {
        Root = new QNode(x,y);
        return true;
    }

    return add(Root, x, y, 0, 0, width, height);
}

// You can write the update for midx and midy!! =) =) =) W00T! W00T!
bool QuadTree::contains(QNode *node, float x, float y) {
    if(node == NULL){
        return false;
    }
    if (node->is_leaf()) {
        return ((node->x == x) && (node->y == y));
    }

    float midx = width/2.0;
    float midy = height/2.0;
    if (x < midx && y < midy) {
        return contains(node->tl, x, y);
    } else if (x < midx && y >= midy) {
        return contains(node->bl, x, y);
    } else if (x >= midx && y < midy) {
        return contains(node->tr, x, y);
    } else {
        return contains(node->br, x, y);
    }

    return false;
}

bool QuadTree::contains(float x, float y) {
    return contains(Root,x,y);
}

/* return the number of points in the box (sx, sy) -> (ex, ey) 
 * You may assume that sx < ex and sy < ey!
 */
int QuadTree::countInRange(float sx, float sy, float ex, float ey) {
}

bool QuadTree::remove(float x, float y) {
}

void QuadTree::print(QNode *node) {
    if (node != NULL) {
        if (node->is_leaf()) {
            std::cout << "( " << node->x << ", " << node->y << ")\n";
            return;
        } else {
            print(node->tl);
            print(node->tr);
            print(node->bl);
            print(node->br);
        }
    }
}

void QuadTree::print() {
    print(Root);
}

#endif
