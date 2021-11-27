use std::cell::RefCell;
use std::cmp::Ordering;
use std::rc::Rc;
impl Solution {
    pub fn search_bst(
        root: Option<Rc<RefCell<TreeNode>>>,
        val: i32,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        if let Some(t) = root {
            let v = t.borrow().val;
            match v.cmp(&val) {
                Ordering::Equal => Some(t),
                Ordering::Greater => Self::search_bst(t.borrow_mut().left.take(), val),
                Ordering::Less => Self::search_bst(t.borrow_mut().right.take(), val),
            }
        } else {
            None
        }
    }
}
