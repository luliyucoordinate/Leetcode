class FileSystem 
{
public:
    bool create(const string& path, int value) 
    {
        auto parent = string(path.begin(), path.begin() + path.rfind('/'));
        if (!parent.empty() && !paths.count(parent)) return false;
        if (paths.count(path)) return false;
        return paths.emplace(path, value).second;
    }

    int get(const string& path)
    {
        if (!paths.count(path)) return -1;
        return paths[path];
    }
private:
    unordered_map<string, int> paths;
};