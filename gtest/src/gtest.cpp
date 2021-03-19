#include "stdafx.h"

using namespace SuperCLine;

int main()
{
	interface_logmgr* logger = load_module_log();
	char exe_path[app_max_path] = { 0 };
	if (!core_util::get_exedir(exe_path, app_max_path))
		return -1;

	ustring cur_path = core_util::get_file_path(exe_path);
	cur_path += "/log_template.config";

	if (!logger->init(cur_path.c_str()))
		return -2;

	logger->logf(ELogType::Debug, "core", "%s", "debug color");
	logger->logf(ELogType::Info, "core", "%s", "info color");
	logger->logf(ELogType::Error, "core", "%s", "error color");
	logger->logf(ELogType::Perf, "core", "%s", "per color");

	unload_module_log(logger);

	system("pause");

	return 0;
}