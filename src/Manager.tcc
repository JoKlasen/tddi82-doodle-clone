
template <typename T>
T & Manager<T>::load (const std::string & file)
{
    auto it { resource_map.find(file) };
    if ( it == resource_map.end () )
    {
        std::unique_ptr<T> tmp { std::make_unique<T> () };
        if ( !tmp -> loadFromFile (file) )
	        throw std::logic_error { "Kunde inte ladda filen?"};
        it = resource_map.insert (std::make_pair (file, std::move(tmp))).first;
    } 
    return *(it->second);
}

template <typename T>
std::unordered_map<std::string, std::unique_ptr<T>> Manager<T>::resource_map { };