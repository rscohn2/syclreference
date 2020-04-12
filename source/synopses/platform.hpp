class platform {
public:
  platform();
  explicit platform(cl_platform_id PlatformId);
  explicit platform(const device_selector &DeviceSelector);
  platform(const platform &rhs) = default;
  platform(platform &&rhs) = default;
  platform &operator=(const platform &rhs) = default;
  platform &operator=(platform &&rhs) = default;
  bool operator==(const platform &rhs) const { return impl == rhs.impl; }
  bool operator!=(const platform &rhs) const { return !(*this == rhs); }
  cl_platform_id get() const;
  bool has_extension(const string_class &ExtensionName) const;
  bool is_host() const;
  vector_class<device>
    get_devices(info::device_type DeviceType = info::device_type::all) const;
  template <info::platform param> typename
    info::param_traits<info::platform, param>::return_type get_info() const;
  static vector_class<platform> get_platforms();
};
