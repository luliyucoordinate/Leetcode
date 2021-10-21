#[derive(Default)]
struct TrieNode {
    child: [Option<Box<TrieNode>>; 26],
    is_end: bool,
}

#[derive(Default)]
struct WordDictionary {
    trie: TrieNode,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl WordDictionary {

    fn new() -> Self {
        Default::default()
    }
    
    fn add_word(&mut self, word: String) {
        let mut node = &mut self.trie;
        for &c in word.as_bytes() {
            node = node.child[(c - b'a') as usize].get_or_insert(Box::new(Default::default()));
        }
        node.is_end = true;
    }
    
    fn search(&self, word: String) -> bool {
        return dfs(word.as_bytes(), 0, &self.trie);
    }
}

fn dfs(word: &[u8], index: usize, node: &TrieNode) -> bool {
    if index == word.len() {
        return node.is_end;
    }

    let &c = word.get(index).unwrap();
    if c >= b'a' && c <= b'z' {
        let ci = (c - b'a') as usize;
        if let Some(t) = &node.child[ci] {
            if dfs(word, index + 1, t) {
                return true;
            }
        }
    } else if c == b'.' {
        for child in node.child.iter() {
            if let Some(t) = child {
                if dfs(word, index + 1, t) {
                    return true;
                }
            }
        }
    }
    false
}