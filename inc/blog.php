{#color:模板色系|value:"#0F3D5E"}
{#color:背景颜色|value:"#ECEEF0"}
{#boolean:显示关注按钮|value:"false"}
{#boolean:显示标签云|value:"false"}
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <title>{$meta.title}</title>
    <meta name="description" content="{$meta.description}">
    <meta name="keywords" content="{$meta.keywords}">
    <link href="{$meta.rss}" rel="alternate" title="订阅{$global.name}" type="application/rss+xml">
    <link rel="shortcut icon" type="image/jpeg" href="{$meta.favicon}">
    <link rel="apple-touch-icon" href="{$meta.mobile_icon}">
    <link rel="stylesheet" href="http://x.libdd.com/farm1/90ecce/2671f8b2/style.css">
    <link rel="stylesheet" href="http://t.libdd.com/css/base/rich-content.css">
    <!--<script type="text/javascript" src="http://t.libdd.com/js/libs/jquery/1.6.4/jquery.js"></script>-->
    <style type="text/css">
        body {
            background-color:{$_背景颜色};	background:url(http://m1.img.libdd.com/farm5/2012/0821/14/EAEA83695CF3AEF8F9C0C06DF9E8EE564D284D9BE40C_481_478.GIF);
        }
        .aside,
        .aside a,
        .aside .pages a,
        .post-box a {
            color: {$_模板色系|color_adjust:"hsv(0,-0.45,0.2)"};
        }
        .aside .tags,
        .aside .pages li {
            border-top:1px solid {$_背景颜色|color_adjust:"hsv(0,0,-0.1)"};
        }
        .aside .pages a:hover,
        .aside .tags a:hover,
        .post-box a:hover,
        .header .title a {
            color: {$_模板色系|color_adjust:"hsv(0,-0.15,0.05)"};
        }
        .aside .info-box,
        .aside .info-box a {
            color: {$_模板色系|color_adjust:"hsv(0,-0.6,0.6)"};
        }
        .aside .info-box a:hover {
            color: {$_模板色系|color_adjust:"hsv(0,-1,1)"};
        }
        .aside .info-box {
            background-color:{$_模板色系};
            box-shadow: inset 0 0 8px {$_模板色系|color_adjust:"hsv(0,-0.2,-0.5)"};
        }
        .aside .info-box,
        .aside .info-box .links a {
            text-shadow:1px 1px 2px {$_模板色系|color_adjust:"hsv(0,-0.2,-0.5)"};
        }
        .aside .info-box .links {
            color: {$_模板色系|color_adjust:"darken(0.2)"};
            text-shadow:1px 0 0 {$_模板色系|color_adjust:"lighten(0.1)"};
        }
        .aside .info-box:hover {
            background-color:{$_模板色系|color_adjust:"hsv(0,0,0.02)"};
            box-shadow: inset 0 0 5px {$_模板色系|color_adjust:"hsv(0,-0.2,-0.5)"};
        }
        .aside .info-box .description {
            border-bottom:1px solid {$_模板色系|color_adjust:"darken(0.2)"};
        }
        .aside .links {
            color: {$_模板色系};
            border-top:1px solid {$_模板色系|color_adjust:"lighten(0.1)"};
        }
        .aside .copyright,
        .aside .copyright a {
            color: {$_模板色系|color_adjust:"hsv(0,-0.8,0.4)"};
        }
		.hua_top,.hua_logo{
			float:left;
		}
		.hua_header { background:url(http://m3.img.libdd.com/farm4/2012/0821/14/0390174C0542488D7BA1DCBC1405DBE8DEC4B0004114_1_77.GIF) repeat-x; height:72px; padding-top:5px;}
    </style>
    <script type="text/javascript" src="http://x.libdd.com/farm1/6be030/f72373f1/9A956.js"></script>
</head>
<body>
    <div class="hua_header">
		<div class="hua_top">
		<div class="hua_logo"><a href="www.huafaner.com"><img src="http://m2.img.libdd.com/farm4/2012/0821/14/28695AED949C821798CCB8B852438C4A98D2419BE40C_170_62.GIF" /></a></div>
		</div>
	</div>
	<div class="header">	
        <h1 class="title">
			<!--<a href="{$global.url}">{$global.name}</a>-->
		</h1>
    </div>
    <div class="container">
        <div class="main">
        {?!posts}
            <div class="posts">
                <div class="post-box post-text">
                    <div class="post-box-header"></div>
                    <div class="post-box-container">
                        <h2 class="title no-content">还没有任何文章哦！</h2>
                    </div>
                    <div class="post-box-footer"></div>
                </div>
            </div>
        {/!posts}
        {?posts}
            <div class="posts">
                {?loop:posts}
                
                <div class="post-box post-{$post.type}">
                    <div class="post-box-header"></div>
                    <div class="post-box-container">
                        {?post.text}
                        {?$text.title}
                            <h2 class="title">{$text.title}</h2>
                        {/$text.title}
                        {?$text.content}
                            <div class="entry rich-content">
                                {$text.content}
                            </div>
                        {/$text.content}
                        {/post.text}

                        {?post.photo}
                        {?$photos.title}
                            <h2 class="title">{$photos.title}</h2>
                        {/$photos.title}
                        <div class="img-container">
                            {?loop:photos}
                                <div class="img-holder"><img src="{$photo.500.src}" alt="{$photo.description|nohtml}" onload="fixImgSize(this)"></div>
                                {?$photo.description}<div class="desc-holder">{$photo.description}</div>{/$photo.description}
                            {/loop:photos}
                        </div>
                        {?$photos.description}
                            <div class="entry rich-content">
                                {$photos.description}
                            </div>
                        {/$photos.description}
                        {/post.photo}

                        {?post.link}
                        <h2 class="title">
                            <a href="{$link.url}">
                                {?$link.title}{$link.title}{/$link.title}
                                {?!$link.title}{$link.url}{/!$link.title} →
                            </a>
                        </h2>
                        {?$link.description}
                            <div class="entry rich-content">
                                {$link.description}
                            </div>
                        {/$link.description}
                        {/post.link}

                        {?post.audio}
                        <div class="audio-cover"><img src="{$audio.cover}" alt="{$audio.song|nohtml} - {$audio.artist|nohtml}" onload="fixImgSize(this)"></div>
                        <div class="audio-player">{$audio.player}</div>
                        {?$audio.description}
                            <div class="entry rich-content">
                                {$audio.description}
                            </div>
                        {/$audio.description}
                        {/post.audio}

                        {?post.video}
                        <div class="video-player">{$video.player}</div>
                        {?$video.description}
                            <div class="entry rich-content">
                                {$video.description}
                            </div>
                        {/$video.description}
                        {/post.video}

                        {?!view.page}
                            <div class="meta">
                                {?post.tag}
                                    <div class="post-tags">
                                    {?loop:post.tags}
                                        <a href="{$post.tag.url}">#{$post.tag.name}</a>
                                    {/loop:post.tags}
                                    </div>
                                {/post.tag}
                                <a class="date" href="{$post.url}">{$post.date}</a>
                                {?!$post.notes_count|eq:"0"}
                                <a class="permalink" href="{$post.url}#notes">
                                    {$post.notes_count} 热度
                                </a>
                                {/!$post.notes_count}
                            </div>
                        {/!view.page}
                    </div>
                    <div class="post-box-footer"></div>
                </div>

                {?view.post}
                    <div id="notes" class="notes">
                        {#sys:notes.link_color|value:$_模板色系}
                        {#sys:notes.text_color|value:"#444444"}
                        {#sys:notes.blockquote_color|value:"#E7EAEE"}
                        {#sys:notes.block_bg_color|value:"#D7DADD"}
                        {#sys:notes.block_border_color|value:"#C7CACC"}
                        {#sys:notes.operation_link_color|value:"#999999"}
                        {#sys:notes.enable_border_radius|value:"true"}
                        {#sys:notes.width|value:"550"}
                        {$post.notes}
                    </div>
                {/view.post}

                {/loop:posts}
            </div>

            {?pagination}
                <div class="pagination">
                    <a class="next{?!pagination.next} disabled{/!pagination.next}"
                        {?pagination.next} href="{$pagination.next.url}"{/pagination.next}>
                        {?view.list}下一页{/view.list}
                        {?view.post}下一篇{/view.post}
                    </a>
                    <a class="prev {?!pagination.prev}disabled{/!pagination.prev}"
                        {?pagination.prev} href="{$pagination.prev.url}"{/pagination.prev}>
                        {?view.list}上一页{/view.list}
                        {?view.post}上一篇{/view.post}
                    </a>
                </div>
            {/pagination}
        {/posts}
        </div>

        <!-- 侧边栏 -->
        <div class="aside">
            <div class="info-box">
                <!-- 头像 -->
                <img class="avatar" src="{$global.cover_200}" alt="{$global.name}">
                <!-- 博客描述 -->
                <div class="description{?$_显示关注按钮} description-with-follow{/$_显示关注按钮}">{$global.description}</div>
                <!-- 常用链接入口 -->
                <div class="links{?$_显示关注按钮} links-with-follow{/$_显示关注按钮}">
                    {?contribute}<a href="{$contribute.url}">{$contribute.title}</a> / {/contribute}
                    {?inbox}<a href="{$inbox.url}">{$inbox.title}</a> / {/inbox}
                    <a href="{$global.archive_url}">存档</a> /
                    <a href="{$meta.rss}">RSS</a>
                </div>
                {?$_显示关注按钮}
                <div class="follow">
                    <a href="{$global.follow_url}" class="follow-btn">关&nbsp;注</a>
                </div>
                {/$_显示关注按钮}
            </div>
            <!-- 自定义页面 -->
            {?pages}
            <ul class="pages">
                {?loop:pages}
                <li><a href="{$page.url}"{?pages@current} class="current"{/pages@current}>{$page.title}</a></li>
                {/loop:pages}
            </ul>
            {/pages}
            
            {?$_显示标签云}
            <!-- 热门标签 -->
                {?tags}
                <div class="tags">
                    {?loop:tags}
                        <a href="{$tag.url}"{?tags@current} class="current"{/tags@current}>{$tag.name}</a>
                    {/loop:tags}
                </div>
                {/tags}
            {/$_显示标签云}

            <div class="search-box">
                <form action="/" method="get">
                    <input class="text" type="text" name="tag" placeholder="搜索">
                    <input class="submit" type="submit" value="搜索">
                </form>
            </div>

            <div class="copyright">
                Powered by <a href="http://www.diandian.com" target="_blank">diandian</a>.
            </div>
        </div>
        <a class="scroll-to-top">返回顶部</a>
    </div>
</body>
</html>


